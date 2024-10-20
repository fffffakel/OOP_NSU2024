#include "gtest/gtest.h"
#include "../src/bitarray.cpp"
#include <iostream>

TEST(BitArrayTest, Constructor) {
    BitArray ba(8);
    ASSERT_EQ(ba.size(), 8);
    ASSERT_FALSE(ba.empty());

    BitArray ba2(8, 0b10101010);
    ASSERT_EQ(ba2.size(), 8);
    ASSERT_EQ(ba2.to_string(), "10101010");
}

TEST(BitArrayTest, SetAndReset) {
    BitArray ba(8);
    ba.set(3, true);
    ASSERT_EQ(ba.to_string(), "00001000");

    ba.reset(3);
    ASSERT_EQ(ba.to_string(), "00000000");

    ba.set();
    ASSERT_EQ(ba.to_string(), "11111111");

    ba.reset();
    ASSERT_EQ(ba.to_string(), "00000000");
}

TEST(BitArrayTest, AnyAndNone) {
    BitArray ba(8);
    ASSERT_TRUE(ba.none());
    ASSERT_FALSE(ba.any());

    ba.set(3, true);
    ASSERT_FALSE(ba.none());
    ASSERT_TRUE(ba.any());
}

TEST(BitArrayTest, OperatorBrackets) {
    BitArray ba(8, 0b10101010);
    ASSERT_FALSE(ba[0]);
    ASSERT_TRUE(ba[1]);
    ASSERT_FALSE(ba[2]);
    ASSERT_TRUE(ba[3]);
}

TEST(BitArrayTest, OperatorEqualAndNotEqual) {
    BitArray ba1(8, 0b10101010);
    BitArray ba2(8, 0b10101010);
    ASSERT_TRUE(ba1 == ba2);
    ASSERT_FALSE(ba1 != ba2);

    BitArray ba3(8, 0b01010101);
    ASSERT_FALSE(ba1 == ba3);
    ASSERT_TRUE(ba1 != ba3);
}

TEST(BitArrayTest, OperatorLogicalOperators) {
    BitArray ba1(8, 0b10101010);
    BitArray ba2(8, 0b01010101);

    BitArray resultAnd = ba1 & ba2;
    ASSERT_EQ(resultAnd.to_string(), "00000000");

    BitArray resultOr = ba1 | ba2;
    ASSERT_EQ(resultOr.to_string(), "11111111");

    BitArray resultXor = ba1 ^ ba2;
    ASSERT_EQ(resultXor.to_string(), "11111111");
}

TEST(BitArrayTest, OperatorShift) {
    BitArray ba1(8, 0b10101010);
    BitArray ba2 = ba1 << 2;
    ASSERT_EQ(ba2.to_string(), "10101000");

    BitArray ba3 = ba1 >> 2;
    ASSERT_EQ(ba3.to_string(), "00101010");
}

TEST(BitArrayTest, Count) {
    BitArray ba1(8, 0b10101010);
    ASSERT_EQ(ba1.count(), 4);

    BitArray ba2(8, 0b00000001);
    ASSERT_EQ(ba2.count(), 1);
}

TEST(BitArrayTest, ToString) {
    BitArray ba1(8, 0b10101010);
    ASSERT_EQ(ba1.to_string(), "10101010");
}

TEST(BitArrayTest, Resize) {
    BitArray ba1(8, 0b10101010);
    ba1.resize(16, true);
    ASSERT_EQ(ba1.size(), 16);
    ASSERT_EQ(ba1.to_string(), "1111111110101010");

    ba1.resize(4, false);
    ASSERT_EQ(ba1.size(), 4);
    ASSERT_EQ(ba1.to_string(), "1010");
}

TEST(BitArrayTest, PushBack) {
    BitArray ba1(4, 0b1010);
    ba1.push_back(true);
    ASSERT_EQ(ba1.size(), 5);
    ASSERT_EQ(ba1.to_string(), "11010");

    ba1.push_back(false);
    ASSERT_EQ(ba1.size(), 6);
    ASSERT_EQ(ba1.to_string(), "011010");
}

TEST(BitArrayTest, Clear) {
    BitArray ba1(8, 0b10101010);
    ba1.clear();
    ASSERT_EQ(ba1.size(), 0);
    ASSERT_TRUE(ba1.empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}