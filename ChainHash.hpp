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
    int defaultSize = 7;
    int arraySize;

    ChainLink* head;

public:

    int hash(int value);

    ChainHash();

    ~ChainHash();

    //Additem

    //FindItem

    //RemoveItem

    //DisplayTable

};

#endif //LAB4_CHAINHASH_HPP
