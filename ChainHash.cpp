//
// Created by Ethan Short on 10/22/23.
//

#include "ChainHash.hpp"

ChainHash::ChainHash() {
    if (tableSize > defaultSize) {
        this->tableSize = tableSize;
    } else {
        this->tableSize = defaultSize;
    }

    theTable = new ChainLink *[tableSize](); // Initialize to nullptr
    //initialize the table
    for (int i = 0; i < tableSize; i++) {
        theTable[i] = nullptr;
    }
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
    // create a new item to add to the hash table
    ChainLink* temp = new ChainLink(value);

    // get the index into the hash array
    int index = hashFunc(value);

    // add to head of list at that location
    temp->setNext(theTable[index]);
    theTable[index] = temp;
}

bool ChainHash::findItem(string value) {
    // get the index into the hash array
    int index = hashFunc(value);

    // search the list at that location
    ChainLink* temp = theTable[index];
    while (temp != nullptr) {
        if (temp->getValue() == value) {
            return true;
        }
        temp = temp->getNext();
    }

    // not found
    return false;
}