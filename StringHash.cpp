//
// Created by Student on 10/19/2023.
//

#include "StringHash.hpp"

//Helper Functions
int StringHash::hashFunc(string key) {
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

void StringHash::resizeArray() {
    int newSize = findNextPrime(arraySize * 2); // Double the size
    std::string* newTable = new std::string[newSize];
    for (int i = 0; i < newSize; i++) {
        newTable[i] = "_empty_";
    }

    for (int i = 0; i < arraySize; i++) {
        if (theArray[i] != "_empty_" && theArray[i] != "_deleted_") {
            int index = hashFunc(theArray[i]);
            while (newTable[index] != "_empty_") {
                index = (index + 1) % newSize; // Linear probing
            }
            newTable[index] = theArray[i];
        }
    }

    delete[] theArray;
    theArray = newTable;
    arraySize = newSize;
}

int StringHash::findNextPrime(int n) {
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

//Constructor
StringHash::StringHash(): temp(0){
    if (arraySize < defaultSize) {
        arraySize = defaultSize;
    } else {
        arraySize = defaultSize;
    }

    theArray = new string[arraySize];

    for (int i = 0; i < arraySize; i++) {
        theArray[i] = EMPTY;
    }
}

StringHash::~StringHash() {
    delete theArray;
}

void StringHash::addItem(string value) {
    if (count >= arraySize / 2) {
        resizeArray();
    }

    index = hashFunc(value);

    while (theArray[index] != EMPTY && theArray[index] != DELETED) {
        index++;

        // wrap when you hit the top end of the array
        if (index >= arraySize) {
            index = 0;
        }
    }

    count++;

    theArray[index] = value;
    cout << YEL << theArray[index] << CLEAR << endl;

}

bool StringHash::findItem(string value) {
    index = hashFunc(value);

    bool done = false;

    while (theArray[index] != EMPTY && !done) {
        if (theArray[index] == value) {
            done = true;
        } else {
            index++;
            if(index >= arraySize) {
                index = 0;
            }
        }
    }

    return done;
}

void StringHash::removeItem(string value) {
index = hashFunc(value);

    bool done = false;

    while (theArray[index] != EMPTY && !done) {
        if (theArray[index] == value) {
            done = true;
            theArray[index] = DELETED;
        } else {
            index++;
            if(index >= arraySize) {
                index = 0;
            }
        }
    }
}

string StringHash::displayTable() {
    string result;

    for (int i = 0; i < arraySize; i++) {
        result += theArray[i];
        result += " ";
    }

    return result;
}