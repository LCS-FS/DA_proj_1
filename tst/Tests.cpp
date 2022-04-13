#include "gtest/gtest.h"
#include "algorithms.h"
#include "Delivery.h"

TEST (CompositionTest, PerfectSquares) {
    EXPECT_EQ(compose(3, 4), 5);
}

TEST (CompositionTest, NonPerfectSquaresRounded) {
    EXPECT_EQ(compose(3, 8), double(8.544));
}

TEST (ComposedDeliveryComparison, ExactSame) {
    Delivery del1 = Delivery(2, 3, 0, 0);
    Delivery del2 = Delivery(2, 3, 0, 0);
    Delivery del3 = del1;

    EXPECT_EQ(false, compareComposedDelivery(del1, del2));
    EXPECT_EQ(false, compareComposedDelivery(del1, del3));
    EXPECT_EQ(false, compareComposedDelivery(del1, del1));
}

TEST (ComposedDeliveryComparison, Smaller) {
    Delivery del1 = Delivery(3, 4, 0, 0);
    Delivery del2 = Delivery(8, 3, 0, 0);

    EXPECT_EQ(true, compareComposedDelivery(del1, del2));
}

TEST (ComposedDeliveryComparison, Bigger) {
    Delivery del1 = Delivery(3, 4, 0, 0);
    Delivery del2 = Delivery(8, 3, 0, 0);

    EXPECT_EQ(false, compareComposedDelivery(del2, del1));
}