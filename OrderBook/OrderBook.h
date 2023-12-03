#pragma once
#include <map>

class OrderBook {
    std::map<int, int> bids, asks; // <price, quantity>
public:
    bool is_empty() const;
    
};
