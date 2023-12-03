#pragma once
#include <map>
#include <iostream>

class OrderBook {
    std::map<int, int> bids, asks; // <price, quantity>
    void add(int price, int quantity, bool is_bid);
public:
    bool is_empty() const;
    void add_bid(int price, int quantity);
    void add_ask(int price, int quantity);

    friend std::ostream& operator<<(std::ostream& os, const OrderBook& order_book); // prints the order book
};
