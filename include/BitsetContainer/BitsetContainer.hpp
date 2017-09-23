#ifndef BITSETCONTAINER_LIBRARY_H
#define BITSETCONTAINER_LIBRARY_H

#include <boost/iterator/iterator_facade.hpp>
#include <bitset>
#include <memory>
#include <iostream>

template<size_t N>
class BitsetIterator : public boost::iterator_facade<
    BitsetIterator<N>, bool, boost::random_access_traversal_tag> {

 public:
  unsigned int index;
  std::bitset<N> bitset;

  BitsetIterator(const std::bitset<N> &bitset, unsigned int index)
      : bitset(bitset), index(index), value(new bool(bitset[index])) {

  }

  ~BitsetIterator() {
    delete value;
  }

 private:
  bool *value;
  friend class boost::iterator_core_access;

  void increment() {
    advance(1);
  };

  void decrement() {
    advance(-1);
  };

  void advance(int n) {
    index += n;
    *value = bitset[index];
  };

  bool equal(const BitsetIterator<N> &other) const {
    return this->index == other.index;
  };

  bool &dereference() const {
    return *value;
  }

  std::ptrdiff_t distance_to(const BitsetIterator<N> &other) const {
    return other.index - this->index;
  }

};

template<size_t N>
class BitsetContainer : public std::bitset<N> {
 public:
  typedef BitsetIterator<N> iterator;
//  typedef std::reverse_iterator<iterator> reverse_iterator;

  explicit BitsetContainer(unsigned long long val) : std::bitset<N>(val) {

  }

  iterator begin() {
    return iterator(*this, 0);
  }

  iterator end() {
    return iterator(*this, static_cast<unsigned int>(N));
  }

};

#endif