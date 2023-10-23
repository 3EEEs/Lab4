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

    int Additem(string value);

    //Helper functions
    int hashFunc(string key) const;

    //FindItem

    //RemoveItem

    //DisplayTable

};

#endif //LAB4_CHAINHASH_HPP
