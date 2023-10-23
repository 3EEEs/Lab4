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
    int tableSize;

    int data;
    int key;

    ChainLink** theTable;

    ChainLink* head;

public:

    ChainHash();

    ~ChainHash();

    //Helper functions
    int hashFunc(string key);

    //Core Methods
    int addItem(string value);

    bool findItem(string value);

    void removeItem(string value);

    //DisplayTable

};

#endif //LAB4_CHAINHASH_HPP
