#include "gtest/gtest.h"
#include "algorithms.h"

TEST (CompositionTest, PerfectSquares) {
    EXPECT_EQ(compose(3, 4), 5);
}

TEST (CompositionTest, NonPerfectSquares) {
    EXPECT_EQ(compose(3, 8), double(8.544));
}