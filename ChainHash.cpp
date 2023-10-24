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
    cout << YEL << "Resizing table" << CLEAR << endl;

    int newSize = nextPrime(tableSize); //Increase the size by the next prime number

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
    tableSize = newSize;

    cout << BLU << tableSize << CLEAR << endl;
}

int ChainHash::nextPrime(int N)
{
    // Base case
    if (N <= 1)
        return 2;

    int prime = N;
    bool found = false;

    // Loop continuously until a prime number is found
    while (!found) {
        prime++;
        found = true; // Assume prime until proven otherwise
        for (int i = 2; i * i <= prime; i++) {
            if (prime % i == 0) {
                found = false; // It's not prime
                break;
            }
        }
    }

    cout << GRN << prime << CLEAR << endl;
    return prime;
}

int ChainHash::addItem(string value) {
    //Check if the table is too full
    cout << RED << data << CLEAR << endl;
    if (data >= tableSize * 2) {
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

    data++;
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
                data--;
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