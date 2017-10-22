#ifndef BITSETCONTAINER_LIBRARY_H
#define BITSETCONTAINER_LIBRARY_H

#include <bitset>
#include <memory>

template<size_t N>
class Iterator {
 public:

  using difference_type = std::ptrdiff_t;
  using value_type = bool;
  using reference = typename std::bitset<N>::reference &;
  using pointer = std::shared_ptr<typename std::bitset<N>::reference>;
  using iterator_category = std::random_access_iterator_tag;

  explicit Iterator(std::bitset<N> *bitsetPtr, int offset = 0)
      : bitsetPtr(bitsetPtr),
        offset(offset),
        current(new typename std::bitset<N>::reference(bitsetPtr->operator[](offset))) {
  }

  Iterator &operator+=(difference_type offset) {
    advance(offset);
    return *this;
  }

  Iterator &operator-=(const int &offset) {
    advance(-offset);
    return *this;
  }

  reference operator*() const {
    return *current;
  }

  pointer operator->() const {
    return current;
  }

  reference operator[](difference_type offset) {
    array.reset(new typename std::bitset<N>::reference(bitsetPtr->operator[](this->offset + offset)));
    return *array;
  }

  Iterator<N> &operator++() {
    advance(1);
    return *this;
  }

  Iterator<N> &operator--() {
    advance(-1);
    return *this;
  }

  Iterator<N> operator++(int) {
    Iterator tmp = *this;
    advance(1);
    return tmp;
  }

  Iterator<N> operator--(int) {
    Iterator tmp(*this);
    advance(-1);
    return tmp;
  }

  difference_type operator-(const Iterator &iterator) const {
    return offset - iterator.offset;
  }

  Iterator<N> operator-(const difference_type offset) const {
    return Iterator(bitsetPtr, this->offset - offset);
  }

  Iterator<N> operator+(difference_type offset) const {
    return Iterator(bitsetPtr, this->offset + offset);
  }

  bool operator==(const Iterator &iterator) const {
    return offset == iterator.offset;
  }

  bool operator!=(const Iterator &iterator) const {
    return offset != iterator.offset;
  }

  bool operator>(const Iterator &iterator) const {
    return *current > *(iterator.current);
  }

  bool operator<(const Iterator &iterator) const {
    return *current < *(iterator.current);
  }

  bool operator>=(const Iterator &iterator) const {
    return *current >= *(iterator.current);
  }

  bool operator<=(const Iterator &iterator) const {
    return *current <= *(iterator.current);
  }

 private:
  void advance(int offset) {
    this->offset += offset;
    current.reset(new typename std::bitset<N>::reference(bitsetPtr->operator[](this->offset)));
  }

 protected:
  std::shared_ptr<typename std::bitset<N>::reference> current;
  std::shared_ptr<typename std::bitset<N>::reference> array;
  int offset;
  std::bitset<N> *bitsetPtr;
};

template<size_t N>
class BitsetContainer : public std::bitset<N> {
 public:

  using iterator = Iterator<N>;
  using reverse_iterator = std::reverse_iterator<iterator>;

  BitsetContainer() : std::bitset<N>() {

  }

  explicit BitsetContainer(unsigned long long val) : std::bitset<N>(val) {

  }

  explicit BitsetContainer(const std::string &string) : std::bitset<N>(string) {

  }

  iterator begin() {
    return Iterator<N>(this, 0);
  }

  iterator end() {
    return Iterator<N>(this, N);
  }

  reverse_iterator rbegin() {
    return reverse_iterator(end());
  }

  reverse_iterator rend() {
    return reverse_iterator(begin());
  }

};

#endif