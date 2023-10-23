//
// Created by Ethan Short on 10/22/23.
//

#include "ChainHash.hpp"

ChainHash::ChainHash() {
    if (tableSize > defaultSize) {
        this->tableSize = defaultSize;
    } else {
        this->tableSize = tableSize;
    }

    ChainLink* theTable[tableSize];
}

//Add more
ChainHash::~ChainHash() {
    delete this->head;
}

//Helper functions
int ChainHash::hashFunc(string key) {
    // initialize index
    int hashValue = 0;

    for (size_t i = 0; i < key.length(); i++) {
        // Multiply current sum
        hashValue *= 128;

        // Add current character's ASCII value
        hashValue += key[i];

        // Shrink to fit within the array size
        hashValue %= tableSize;
    }

// return the result
    return hashValue;
}

int ChainHash::addItem(string value) {
    int index = hashFunc(value);

    ChainHash* newItem = new ChainHash(key, value);

    newItem->getNext() = theTable[index];

    // Update the head of the chain to the new item
    theTable[index] = newItem;

    return index;
}
/*
// add a new item in the list with key as value
addValue(value)
// create a new item with that value
temp = new ChainItem(value)

// get the index into the hash array
index = hash(value)

// add to head of list at that location
temp.setNext(theTable[index])
theTable[index] = temp
// look for an item containing key
findValue(value)
*/
bool ChainHash::findItem(string value) {
    int index = hashFunc(value);

    if (theTable[index] == value) {
        return true;
    } else {
        return false;
    }
}