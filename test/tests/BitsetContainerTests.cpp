#include <BitsetContainer/BitsetContainer.hpp>
#include <gtest/gtest.h>
#include <numeric>

TEST(BitsetContainerTest, basicConstruct) {
  const int bits = 0b11111111;
  BitsetContainer<8> bitsetContainer(bits);
  std::bitset<8> bitset(bits);


  int i = 0;
  for (auto bit : bitsetContainer) {
    EXPECT_EQ(bit, bitset[i]);
    i++;
  }
}

TEST(BitsetContainerTest, inputIteratorTest) {
  BitsetContainer<8> bitsetContainer(0b11111111);

  int sum = std::accumulate(bitsetContainer.begin(), bitsetContainer.end(), 0);

  int product = std::accumulate(bitsetContainer.begin(), bitsetContainer.end(), 1, std::multiplies<>());

  ASSERT_EQ(sum, 8);
  ASSERT_EQ(product, 1);
}

TEST(BitsetContainerTest, forwardIteratorTest) {
  BitsetContainer<8> bitsetContainer(0b00111100);

  auto num1s = std::count(bitsetContainer.begin(), bitsetContainer.end(), 1);
  auto num0s = std::count(bitsetContainer.begin(), bitsetContainer.end(), 0);

  ASSERT_EQ(num0s, 4);
  ASSERT_EQ(num1s, 4);
}

TEST(BitsetContainerTest, randomIteratorTest) {
  BitsetContainer<8> bitsetContainer(0b00001111);

  std::sort(bitsetContainer.begin(), bitsetContainer.end());

  ASSERT_EQ(bitsetContainer.to_string(), "11110000");

//  std::rotate(bitsetContainer.begin(), bitsetContainer.begin() + 4, bitsetContainer.end());
//
//  ASSERT_EQ(bitsetContainer.to_string(), "00001111");
}