#pragma once
#include <map>
#include <iostream>
#include <boost/optional.hpp>

class OrderBook {
    std::map<int, int> bids, asks; // <price, quantity>
    void add(int price, int quantity, bool is_bid);
public:
    struct BidAsk { // represents the best bid and ask
        typedef boost::optional<std::pair<int,int>> Entry;
        Entry bid, ask;
        boost::optional<int> spread() const;
    }
    bool is_empty() const;
    void add_bid(int price, int quantity);
    void add_ask(int price, int quantity);
    void remove_bid(int price, int quantity);
    void remove_ask(int price, int quantity);

    BidAsk get_bid_ask() const;

    friend std::ostream& operator<<(std::ostream& os, const OrderBook& order_book); // prints the order book
    friend std::ostream& operator<<(std::ostream& os, const OrderBook::BidAsk& bid_ask); // prints the best bid and ask
};
