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

    ChainLink* newLink = new ChainLink(index, value);

    if (theTable[index] == nullptr) {
        theTable[index] = newLink;
    } else {
        ChainLink* temp = theTable[index];
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newLink);
    }

    return index;
}

bool ChainHash::findItem(string value) {
    int index = hashFunc(value);
    return false;
/*
    if (theTable[index] == value) {
        return true;
    } else {
        return false;
    }
    */
}