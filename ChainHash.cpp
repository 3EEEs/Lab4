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

void ChainHash::resizeTable() {
    int newSize = findNextPrime(tableSize * 2); // Double the size

    //create a new table
    ChainLink **newTable = new ChainLink *[newSize]();

    //copy the old table into the new table
    for (int i = 0; i < tableSize; i++) {
        newTable[i] = theTable[i];
    }

    //delete the old table
    delete[] theTable;

    //set the new table to the old table
    theTable = newTable;

    //set the new table size
    tableSize *= 2;
}

int ChainHash::findNextPrime(int n) {
    bool isPrime = false;
    while (!isPrime) {
        isPrime = true;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (!isPrime) {
            n++;
        }
    }
    return n;
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

void ChainHash::removeItem(string value) {
    //get the index into the hash array
    int index = hashFunc(value);

    if (theTable[index] != nullptr) {
        //search the list at that location
        ChainLink* temp = theTable[index];
        ChainLink* prev = nullptr;
        while (temp != nullptr) {
            if (temp->getValue() == value) {
                if (prev == nullptr) {
                    theTable[index] = temp->getNext();
                } else {
                    prev->setNext(temp->getNext());
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->getNext();
        }
    }
}

string ChainHash::displayTable() {
    string result;
    for (int i = 0; i < tableSize; i++) {
        result += std::to_string(i) + ": ";
        ChainLink* temp = theTable[i];
        while (temp != nullptr) {
            result += temp->getValue() + " ";
            temp = temp->getNext();
        }
        result += "\n";
    }
    return result;
}