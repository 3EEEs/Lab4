//
// Created by Ethan Short on 10/22/23.
//

#ifndef LAB4_CHAINHASH_HPP
#define LAB4_CHAINHASH_HPP

#include "StringHash.hpp"
#include "ChainLink.hpp"

using namespace std;

class ChainHash {
private:


public:
    // constructor

    //Destructor

    //Additem

    //FindItem

    //RemoveItem

    //DisplayTable


// access methods ? might not use

    ChainLink* getNext() {
        return this->next;
    }

    void setNext(ChainLink* next) {
        this->next = next;
    }
};

#endif //LAB4_CHAINHASH_HPP
