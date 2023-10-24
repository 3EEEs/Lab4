//
// Created by Ethan Short on 10/22/23.
//

#ifndef LAB4_CHAINLINK_HPP
#define LAB4_CHAINLINK_HPP

#include <iostream>

using namespace std;

class ChainLink : public __thread_id {
public:
    std::string value; // Data stored in the item
    ChainLink* next; // Pointer to the next item in the chain (for chaining)

    // Constructor to initialize the ChainItem
    ChainLink(string value) : value(value), next(nullptr) {}

    // Getter method for retrieving the data
    std::string getValue() {
        return value;
    }

    // Setter method for updating the data
    void setData(const std::string& newValue) {
        value = newValue;
    }

    // Getter method for retrieving the next item in the chain
    ChainLink* getNext() {
        return next;
    }

    // Setter method for updating the next item in the chain
    void setNext(ChainLink* newNext) {
        next = newNext;
    }
};

#endif //LAB4_CHAINLINK_HPP
