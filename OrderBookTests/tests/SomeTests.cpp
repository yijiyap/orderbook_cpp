#include <gtest/gtest.h>
#include "OrderBook.h"

TEST(OrderBookTests, OrderBookEmptyByDefault) {
    OrderBook order_book;
    EXPECT_TRUE(order_book.is_empty());
}

TEST(OrderBookTests, OrderBookAddBid) {
    OrderBook order_book;
    order_book.add_bid(12, 34);
    EXPECT_FALSE(order_book.is_empty());
}