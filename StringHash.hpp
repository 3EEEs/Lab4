//
// Created by Student on 10/19/2023.
//

#ifndef LAB4_STRINGHASH_HPP
#define LAB4_STRINGHASH_HPP

class StringHash {
private:
    int defaultSize = 11;

public:

    StringHash()::StringHash();

    StringHash::~StringHash();

    void addItem(value);

    void findItem(value);

    void removeItem(value);

    string displayTable();
};

#endif //LAB4_STRINGHASH_HPP
