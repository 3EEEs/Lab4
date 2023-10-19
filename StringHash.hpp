//
// Created by Student on 10/19/2023.
//

#ifndef LAB4_STRINGHASH_HPP
#define LAB4_STRINGHASH_HPP

#include <iostream>

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

//Reset
#define reset "\e[0m"

class StringHash {
private:
    int defaultSize = 11;

    int *theArray;

public:

    StringHash(int size = defaultSize);

    ~StringHash();

    void addItem(int value);

    bool findItem(int value);

    void removeItem(int value);

    string displayTable();
};

#endif //LAB4_STRINGHASH_HPP
