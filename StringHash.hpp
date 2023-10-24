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

//Clear
#define CLEAR "\e[0m"

class StringHash {
private:
    int defaultSize = 11;
    int arraySize;

    int count;
    int index;

    const string EMPTY = "_empty_";
    const string DELETED = "_deleted_";

    string *theArray;

public:

    //Helper Functions
    [[nodiscard]] int hashFunc(string key) const;

    void resizeArray();

    int findNextPrime(int n);


    //Constructor / Destructor
    explicit StringHash();

    ~StringHash();

    //Core Methods
    void addItem(string value);

    bool findItem(string value);

    void removeItem(string value);

    string displayTable();
};

#endif //LAB4_STRINGHASH_HPP
