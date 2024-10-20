#include <gtest/gtest.h>
#include "../src/time.cpp" 

TEST(TimeTest, DefaultConstructor) {
    Time t;
    EXPECT_EQ(t.ToSeconds(), 0);
}

TEST(TimeTest, ParameterizedConstructor) {
    Time t(1, 30, 45);
    EXPECT_EQ(t.ToSeconds(), 5445);
}

TEST(TimeTest, Normalization) {
    Time t(25, 65, 70);
    EXPECT_EQ(t.ToSeconds(), 7570);
}

TEST(TimeTest, AdditionOperator) {
    Time t1(1, 30, 45);
    Time t2(2, 45, 30);
    Time t3 = t1 + t2;
    EXPECT_EQ(t3.ToSeconds(), 15375);
}

TEST(TimeTest, AdditionAssignmentOperator) {
    Time t1(1, 30, 45);
    Time t2(2, 45, 30);
    t1 += t2;
    EXPECT_EQ(t1.ToSeconds(), 15375);
}

TEST(TimeTest, SubtractionOperator) {
    Time t1(3, 45, 30);
    Time t2(1, 30, 45);
    Time t3 = t1 - t2;
    EXPECT_EQ(t3.ToSeconds(), 8085);
}

TEST(TimeTest, SubtractionAssignmentOperator) {
    Time t1(3, 45, 30);
    Time t2(1, 30, 45);
    t1 -= t2;
    EXPECT_EQ(t1.ToSeconds(), 8085);
}

TEST(TimeTest, EqualityOperator) {
    Time t1(1, 30, 45);
    Time t2(1, 30, 45);
    EXPECT_TRUE(t1 == t2);
}

TEST(TimeTest, InequalityOperator) {
    Time t1(1, 30, 45);
    Time t2(2, 45, 30);
    EXPECT_FALSE(t1 == t2);
}

