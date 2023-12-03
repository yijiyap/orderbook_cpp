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