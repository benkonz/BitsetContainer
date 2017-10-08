#ifndef BITSETCONTAINER_LIBRARY_H
#define BITSETCONTAINER_LIBRARY_H

#include <bitset>
#include <iostream>

template<size_t N>
class Iterator {
 public:

  using difference_type = std::ptrdiff_t;
  using value_type = bool;
  using reference = typename std::bitset<N>::reference &;
  using pointer = typename std::bitset<N>::reference *;
  using iterator_category = std::random_access_iterator_tag;

  explicit Iterator(std::bitset<N> &bitset, int offset = 0)
      : bitset(bitset),
        offset(offset),
        current(new typename std::bitset<N>::reference(bitset[offset])),
        array(new typename std::bitset<N>::reference(bitset[offset])) {

  }

  Iterator &operator=(const Iterator &iterator) {
    bitset = iterator.bitset;
    offset = iterator.offset;
    current = iterator.current;
    array = iterator.array;
    return *this;
  }

  ~Iterator() {
//    delete current;
//    delete array;
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
//    delete array;
    array = new typename std::bitset<N>::reference(bitset[this->offset + offset]);
    return *array;
  }

  Iterator<8> &operator++() {
    advance(1);
    return *this;
  }

  Iterator &operator--() {
    advance(-1);
    return *this;
  }

  Iterator operator++(int) {
    Iterator tmp = *this;
    advance(1);
    return tmp;
  }

  Iterator operator--(int) {
    Iterator tmp(*this);
    advance(-1);
    return tmp;
  }

  difference_type operator-(const Iterator &iterator) const {
    return offset - iterator.offset;
  }

  Iterator operator-(const difference_type offset) const {
    return Iterator(bitset, this->offset - offset);
  }

  Iterator operator+(difference_type offset) const {
    return Iterator(bitset, this->offset + offset);
  }

  bool operator==(const Iterator &iterator) const {
    return offset == iterator.offset;
  }

  bool operator!=(const Iterator &iterator) const {
    return offset != iterator.offset;
  }

  bool operator>(const Iterator &iterator) const {
    return *current > *iterator.current;
  }

  bool operator<(const Iterator &iterator) const {
    return *current < *iterator.current;
  }

  bool operator>=(const Iterator &iterator) const {
    return *current >= *iterator.current;
  }

  bool operator<=(const Iterator &iterator) const {
    return *current <= *iterator.current;
  }

 private:
  void advance(int offset) {
    this->offset += offset;
    delete current;
    current = new typename std::bitset<N>::reference(bitset[this->offset]);
  }

 protected:
  typename std::bitset<N>::reference *current;
  typename std::bitset<N>::reference *array;
  int offset;
  std::bitset<N> &bitset;
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