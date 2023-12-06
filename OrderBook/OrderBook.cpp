#include "OrderBook.h"

bool OrderBook::is_empty() const {
    return bids.empty() && asks.empty();
}

void OrderBook::add_bid(int price, int quantity) {
    add(price, quantity, true);
}

void OrderBook::add_ask(int price, int quantity) {
    add(price, quantity, false);   
}

void OrderBook::add(int price, int quantity, bool is_bid) {
    if (is_bid)
        bids[price] += quantity;
    else
        asks[price] += quantity;
}

std::ostream& operator<<(std::ostream& os, const OrderBook& order_book) {
    if (order_book.is_empty()) {
        os << "Order book is empty" << std::endl;
        return os;
    }

    for (auto it = order_book.bids.rbegin(); it != order_book.bids.rend(); ++it) // print from highest to lowest price
        os << "BID " << it->first << " " << it->second << std::endl;
    os << "-------------------" << std::endl;
    for (auto it = order_book.asks.rbegin(); it != order_book.asks.rend(); ++it)
        os << "ASK " << it->first << " " << it->second << std::endl;
    return os;
}

OrderBook::BidAsk OrderBook::get_bid_ask() const {
    BidAsk bid_ask;
    if (!bids.empty())
        bid_ask.bid = std::make_pair(bids.rbegin()->first, bids.rbegin()->second);
    if (!asks.empty())
        bid_ask.ask = std::make_pair(asks.begin()->first, asks.begin()->second);
    return bid_ask;
}

boost::optional<int> OrderBook::BidAsk::spread() const {
    if (!bid.is_initialized() || !ask.is_initialized())
        return boost::none;
    return ask.get().first - bid.get().first;
}

void OrderBook::remove_bid(int price, int quantity) {
    remove(price, quantity, true);
}

void OrderBook::remove_ask(int price, int quantity) {
    remove(price, quantity, false);
}

void OrderBook::remove(int price, int quantity, bool is_bid) {
    if (is_bid) {
        auto it = bids.find(price);
        if (it == bids.end())
            return;
        it->second -= quantity;
        if (it->second <= 0)
            bids.erase(it);
    } else {
        auto it = asks.find(price);
        if (it == asks.end())
            return;
        it->second -= quantity;
        if (it->second <= 0)
            asks.erase(it);
    }
}
