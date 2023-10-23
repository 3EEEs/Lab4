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

    int temp;
    int count;

    string* theTable;

    ChainLink* head;

public:

    ChainHash();

    ~ChainHash();

    //Helper functions
    int hashFunc(string key) const;

    //Core Methods
    int addItem(string value);

    bool findItem(string value);

    //RemoveItem

    //DisplayTable

};

#endif //LAB4_CHAINHASH_HPP
