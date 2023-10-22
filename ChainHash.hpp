//
// Created by Ethan Short on 10/22/23.
//

#ifndef LAB4_CHAINHASH_HPP
#define LAB4_CHAINHASH_HPP

#include <iostream>
#include <sstream>

using namespace std;

class ChainHash {
    int value;
    ChainHash* next;

public:
// constructor
    explicit ChainHash(int val) : value(val), next(nullptr) {}

// access methods ? might not use

    ChainHash* getNext() {
        return this->next;
    }

    void setNext(ChainHash* next) {
        this->next = next;
    }
};

#endif //LAB4_CHAINHASH_HPP
