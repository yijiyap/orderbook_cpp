#include <gtest/gtest.h>
#include "OrderBook.h"

TEST(OrderBookTests, OrderBookEmptyByDefault) {
    OrderBook order_book;
    EXPECT_TRUE(order_book.is_empty());
}