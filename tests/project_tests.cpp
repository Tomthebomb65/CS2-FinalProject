#include <gtest/gtest.h>
#include "alerts_list.h"
#include "crew_members.h"
#include "bst.h"

TEST(Basics, Simple) {
    EXPECT_EQ(1+1, 2);
    EXPECT_TRUE(1+1 == 2);
}

TEST(Basics, multiplyFunction) {
    EXPECT_EQ(48, 48);
}

TEST(HelloSuite, StringsCompare) {
    std::string greeting = "hello";
    EXPECT_EQ(greeting, "hello");
    EXPECT_NE(greeting, "world");
}
//Use test fixtures