//
// Created by Ethan Short on 10/22/23.
//

#ifndef LAB4_CHAINHASH_HPP
#define LAB4_CHAINHASH_HPP

#include "ChainLink.hpp"

class ChainHash {
private:
    int defaultSize = 7;
    int tableSize;

    int data;

    ChainLink** theTable;

    ChainLink* head;

public:

    ChainHash();

    ~ChainHash();

    //Helper functions
    int hashFunc(string key);

    void resizeTable();

    int nextPrime(int n);

    //Core Methods
    int addItem(string value);

    bool findItem(string value);

    void removeItem(string value);

    string displayTable();

};

#endif //LAB4_CHAINHASH_HPP
