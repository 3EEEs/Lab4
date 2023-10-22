//
// Created by Student on 10/19/2023.
//

#ifndef LAB4_STRINGHASH_HPP
#define LAB4_STRINGHASH_HPP

#include <iostream>
#include "ChainHash.hpp"

using namespace std;

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Clear
#define CLEAR "\e[0m"

class StringHash {
private:
    int defaultSize = 11;
    int arraySize;
    int temp;

    int count;
    int index;

    int *theArray;

    ChainHash* head;

public:

    //Helper Functions
    int hashFunc(string key);

    explicit StringHash(int arraySize, int size);

    ~StringHash();

    void addItem(int value);

    bool findItem(int value);

    void removeItem(int value);

    string displayTable();
};

#endif //LAB4_STRINGHASH_HPP
