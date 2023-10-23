//
// Created by Ethan Short on 10/22/23.
//

#include "ChainHash.hpp"

ChainHash::ChainHash() {
    if (arraySize > defaultSize) {
        this->arraySize = defaultSize;
    } else {
        this->arraySize = arraySize;
    }

    theTable = new string[arraySize];

}

//Add more
ChainHash::~ChainHash() {
    delete this->head;
}

//Helper functions
int ChainHash::hashFunc(string key) const {
    // initialize index
    int hashValue = 0;

    for (size_t i = 0; i < key.length(); i++) {
        // Multiply current sum
        hashValue *= 128;

        // Add current character's ASCII value
        hashValue += key[i];

        // Shrink to fit within the array size
        hashValue %= arraySize;
    }

// return the result
    return hashValue;
}

int ChainHash::Additem(string value) {
    int index = hashFunc(value);


    theTable[index] = temp;

    return index;
}