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
    int oldTableSize = tableSize; //Increase the size by the next prime number
    tableSize = nextPrime(tableSize); //Set current

    //create a new table
    ChainLink **newTable = new ChainLink *[tableSize]();

    for (int i = 0; i < oldTableSize; i++) {
        ChainLink *currentLink = theTable[i];

        while (currentLink != nullptr) {
            // create a new item to add to the hash table
            ChainLink* temp = new ChainLink(currentLink->getValue());

            // get the index into the hash array
            int index = hashFunc(currentLink->getValue());

            // add to head of list at that location
            temp->setNext(newTable[index]);
            newTable[index] = temp;

            currentLink = currentLink->getNext(); //Move to the next item in the old table
        }
    }

    count = count;

    //delete the old table
    delete[] theTable;

    //set the new table to the old table
    theTable = newTable;

    //set the new table size
    tableSize = tableSize;
}

int ChainHash::nextPrime(int N) {
    int doubleN = N * 2;
    int upPrime = doubleN + 1;
    int downPrime = doubleN - 1;

    while (true) {
        bool foundUp = isPrime(upPrime);
        bool foundDown = isPrime(downPrime);

        if (foundUp && foundDown) {
            if (upPrime - doubleN <= doubleN - downPrime) {
                return upPrime;
            } else {
                return downPrime;
            }
        } else if (foundUp) {
            return upPrime;
        } else if (foundDown) {
            return downPrime;
        }

        upPrime++;
        downPrime--;
    }
}

bool ChainHash::isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;

    return true;
}

void ChainHash::addItem(string value) {
    //Check if the table is too full
     if (count >= tableSize * 2) {
        // If the number of items is more than twice the table size, resize the table.
        resizeTable();
     }

    // create a new item to add to the hash table
    ChainLink* temp = new ChainLink(value);

    // get the index into the hash array
    int index = hashFunc(value);

    // add to head of list at that location
    temp->setNext(theTable[index]);
    theTable[index] = temp;

    count++;
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
                count--;
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