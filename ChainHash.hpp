//
// Created by Ethan Short on 10/22/23.
//

#ifndef LAB4_CHAINHASH_HPP
#define LAB4_CHAINHASH_HPP

#include "ChainLink.hpp"

//Colors
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define CLEAR "\e[0m"

class ChainHash {
private:
    int defaultSize = 7;
    int tableSize;

    int data{};
    int count{};

    ChainLink** theTable;

    ChainLink* head{};

public:

    ChainHash();

    ~ChainHash();

    //Helper functions
    int hashFunc(string key);

    void resizeTable();

    int nextPrime(int n);

    bool isPrime(int n);

    //Core Methods
    void addItem(string value);

    bool findItem(string value);

    void removeItem(string value);

    string displayTable();

};

#endif //LAB4_CHAINHASH_HPP
