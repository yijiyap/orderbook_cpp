#include <gtest/gtest.h>
#include "OrderBook.h"

TEST(OrderBookTests, OrderBookEmptyByDefault) {
    OrderBook order_book;
    EXPECT_TRUE(order_book.is_empty());
}

TEST(OrderBookTests, OrderBookAddBid) {
    OrderBook order_book;
    order_book.add_bid(12, 34);
    auto bid_ask = order_book.get_bid_ask();
    EXPECT_TRUE(bid_ask.bid.is_initialized());
    auto bid = bidask.bid.get();
    EXPECT_EQ(bid.first, 12);
    EXPECT_EQ(bid.second, 34);
}