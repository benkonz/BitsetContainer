#ifndef BITSETCONTAINER_LIBRARY_H
#define BITSETCONTAINER_LIBRARY_H

#include <bitset>

template<size_t N>
class Iterator : public std::iterator<std::random_access_iterator_tag, bool> {
 public:
  using difference_type = typename std::iterator<std::random_access_iterator_tag, bool>::difference_type;

  Iterator() : bitset(), offset(0) {

  }

  explicit Iterator(const std::bitset<N> &bitset, int offset = 0) : bitset(bitset), offset(offset) {

  }

  Iterator &operator+=(const int &offset) {
    advance(offset);
    return *this;
  }

  Iterator &operator-=(const int &offset) {
    advance(-offset);
    return *this;
  }

  bool &operator*() {
    value = bitset[offset];
    return value;
  }

  bool *operator->() {
    value = bitset[offset];
    return &value;
  }

  bool &operator[](const int &offset) {
    value = bitset[this->offset + offset];
    return value;
  }

  Iterator &operator++() {
    advance(1);
    return *this;
  }

  Iterator &operator--() {
    advance(-1);
    return *this;
  }

  Iterator operator++(int) {
    Iterator tmp(*this);
    advance(1);
    return tmp;
  }

  Iterator operator--(int) {
    Iterator tmp(*this);
    advance(-1);
    return tmp;
  }

  Iterator operator-(const Iterator &iterator) const {
    return Iterator(bitset, offset - iterator.offset);
  }

  Iterator operator+(const Iterator &iterator) const {
    return Iterator(bitset, offset + iterator.offset);
  }

  bool operator==(const Iterator &iterator) const {
    return offset == iterator.offset;
  }

  bool operator!=(const Iterator &iterator) const {
    return offset != iterator.offset;
  }

  bool operator>(const Iterator &iterator) const {
    return offset > iterator.offset;
  }

  bool operator<(const Iterator &iterator) const {
    return offset < iterator.offset;
  }

  bool operator>=(const Iterator &iterator) const {
    return offset >= iterator.offset;
  }

  bool operator<=(const Iterator &iterator) const {
    return offset <= iterator.offset;
  }

 private:
  void advance(int offset) {
    this->offset += offset;
  }

 protected:
  int offset;
  bool value;
  const std::bitset<N> &bitset;
};

template<size_t N>
class BitsetContainer : public std::bitset<N> {
 public:

  BitsetContainer() : std::bitset<N>() {

  }

  explicit BitsetContainer(unsigned long long val) : std::bitset<N>(val) {

  }

  explicit BitsetContainer(std::string string) : std::bitset<N>(string) {

  }

  Iterator<N> begin() {
    return Iterator<N>(*this, 0);
  }

  Iterator<N> end() {
    return Iterator<N>(*this, N);
  }
};

#endif