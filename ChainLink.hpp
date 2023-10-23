//
// Created by Ethan Short on 10/22/23.
//

#ifndef LAB4_CHAINLINK_HPP
#define LAB4_CHAINLINK_HPP

class ChainLink {
public:
    int key;        // Key associated with the item
    std::string data; // Data stored in the item
    ChainLink* next; // Pointer to the next item in the chain (for chaining)

    // Constructor to initialize the ChainItem
    ChainLink(int k, const std::string& d) : key(k), data(d), next(nullptr) {}

    // Getter method for retrieving the key
    int getKey() {
        return key;
    }

    // Getter method for retrieving the data
    std::string getData() {
        return data;
    }

    // Setter method for updating the data
    void setData(const std::string& newData) {
        data = newData;
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
