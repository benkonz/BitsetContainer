#include <BitsetContainer/BitsetContainer.hpp>
#include <gtest/gtest.h>

class BitsetIteratorTest : public ::testing::Test {
 protected:
  BitsetIteratorTest() : bitsetContainer(0b01010101),
                         begin(bitsetContainer.begin()),
                         end(bitsetContainer.end()) {

  }

 protected:
  BitsetContainer<8> bitsetContainer;
  Iterator<8> begin;
  Iterator<8> end;
};

TEST_F(BitsetIteratorTest, Add) {
  auto next = begin + 1;
  EXPECT_EQ(0, *next);
}

TEST_F(BitsetIteratorTest, Subtract) {
  auto previous = end - 1;
  EXPECT_EQ(0, *previous);
}

TEST_F(BitsetIteratorTest, PreIncrement) {
  auto current = ++begin;
  EXPECT_EQ(0, *begin);
  EXPECT_EQ(0, *current);
}

TEST_F(BitsetIteratorTest, PreDecrement) {
  auto current = --end;
  EXPECT_EQ(0, *end);
  EXPECT_EQ(0, *current);
}

TEST_F(BitsetIteratorTest, PostIncrement) {
  auto previous = begin++;
  EXPECT_EQ(0, *begin);
  EXPECT_EQ(1, *previous);
}

TEST_F(BitsetIteratorTest, PostDecrement) {
  auto previous = end--;
  EXPECT_EQ(0, *end);
  EXPECT_EQ(0, *(previous - 1));
}

TEST_F(BitsetIteratorTest, AddEquals) {
  begin += 3;
  EXPECT_EQ(0, *begin);
}

TEST_F(BitsetIteratorTest, SubtractEquals) {
  end -= 3;
  EXPECT_EQ(0, *end);
}

TEST_F(BitsetIteratorTest, Equals) {
  EXPECT_TRUE(begin == bitsetContainer.begin());
}

TEST_F(BitsetIteratorTest, NotEquals) {
  EXPECT_TRUE(begin != end);
}

TEST_F(BitsetIteratorTest, GreaterThan) {
  EXPECT_TRUE(begin > begin + 1);
  EXPECT_FALSE(begin > begin + 2);
}

TEST_F(BitsetIteratorTest, LessThan) {
  EXPECT_TRUE(begin + 1 < begin);
  EXPECT_FALSE(begin < begin + 1);
}

TEST_F(BitsetIteratorTest, GreaterThanOrEqual) {
  EXPECT_TRUE(begin >= begin + 2);
  EXPECT_FALSE(begin + 1 >= begin + 2);
}

TEST_F(BitsetIteratorTest, LessThanOrEqual) {
  EXPECT_TRUE(begin + 1 <= begin);
  EXPECT_TRUE(begin + 1 <= begin + 3);
  EXPECT_FALSE(begin <= begin + 1);
}

TEST_F(BitsetIteratorTest, Dereference) {
  EXPECT_EQ(1, *begin);
}

TEST_F(BitsetIteratorTest, Array) {
  EXPECT_EQ(1, begin[4]);
}