#include <BitsetContainer/BitsetContainer.hpp>
#include <gtest/gtest.h>

TEST(BitsetContainerTest, BasicConstruct) {
  const int bits = 0b00110011;
  BitsetContainer<8> bitsetContainer(bits);
  std::bitset<8> bitset(bits);

  int i = 0;
  for (auto bit : bitsetContainer) {
    EXPECT_EQ(bit, bitset[i]);
    i++;
  }
}

TEST(BitsetContainerTest, BasicCopy) {
  BitsetContainer<8> bitsetContainer(0b00110011);
  std::vector<bool> bucket(8);

  std::copy(bitsetContainer.begin(), bitsetContainer.end(), bucket.begin());

  for(auto i = 0; i < bitsetContainer.size(); i++) {
    EXPECT_EQ(bitsetContainer[i], bucket[i]);
  }
}
