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

TEST(OrderBookTests, OrderBookAddAsk) {
    OrderBook order_book;
    order_book.add_ask(12, 34);
    auto bid_ask = order_book.get_bid_ask();
    EXPECT_TRUE(bid_ask.ask.is_initialized());
    auto ask = bid_ask.ask.get();
    EXPECT_EQ(ask.first, 12);
    EXPECT_EQ(ask.second, 34);
}

TEST(OrderBookTests, OrderBookAddBidAndAsk) {
    OrderBook order_book;
    order_book.add_bid(12, 34);
    order_book.add_ask(13, 35);
    auto bid_ask = order_book.get_bid_ask();
    EXPECT_TRUE(bid_ask.bid.is_initialized());
    EXPECT_TRUE(bid_ask.ask.is_initialized());
    auto bid = bid_ask.bid.get();
    auto ask = bid_ask.ask.get();
    EXPECT_EQ(bid.first, 12);
    EXPECT_EQ(bid.second, 34);
    EXPECT_EQ(ask.first, 13);
    EXPECT_EQ(ask.second, 35);
}

TEST(OrderBookTests, OrderBookRemoveBid) {
    OrderBook order_book;
    order_book.add_bid(12, 34);
    order_book.remove_bid(12, 34);
    auto bid_ask = order_book.get_bid_ask();
    EXPECT_FALSE(bid_ask.bid.is_initialized());
    EXPECT_FALSE(bid_ask.ask.is_initialized());
}

TEST(OrderBookTests, OrderBookRemoveAsk) {
    OrderBook order_book;
    order_book.add_ask(12, 34);
    order_book.remove_ask(12, 34);
    auto bid_ask = order_book.get_bid_ask();
    EXPECT_FALSE(bid_ask.bid.is_initialized());
    EXPECT_FALSE(bid_ask.ask.is_initialized());
}

TEST(OrderBookTests, OrderBookRemoveBidAndAsk) {
    OrderBook order_book;
    order_book.add_bid(12, 34);
    order_book.add_ask(13, 35);
    order_book.remove_bid(12, 34);
    order_book.remove_ask(13, 35);
    auto bid_ask = order_book.get_bid_ask();
    EXPECT_FALSE(bid_ask.bid.is_initialized());
    EXPECT_FALSE(bid_ask.ask.is_initialized());
}

TEST(OrderBookTests, SpreadCalculatedCorrectly) {
    OrderBook order_book;
    order_book.add_bid(12, 34);
    order_book.add_ask(13, 35);
    auto bid_ask = order_book.get_bid_ask();
    EXPECT_TRUE(bid_ask.spread().is_initialized());
    EXPECT_EQ(bid_ask.spread().get(), 1);
}