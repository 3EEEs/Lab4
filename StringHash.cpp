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
        hashValue += static_cast<int>(key[i]);

        // Shrink to fit within the array size
        hashValue %= arraySize;
    }

// return the result
        return hashValue;
}

//Constructor
StringHash::StringHash(int arraySize, int size): arraySize(arraySize) {
    if(size > defaultSize) {
            theArray = new int[arraySize];
    } else {
        theArray = new int[defaultSize];
    }

    count = 0;
    index = 0;

    //Init all to empty (-1)
    for (int i = 0; i < arraySize; i++) {
        theArray[i] = -1;
    }

}

//Destructor /Must update
StringHash::~StringHash() {
    delete theArray;
}

void StringHash::addItem(int value) {
    if (count >= arraySize / 2) {
        throw out_of_range(RED "Table Full" CLEAR);
    }

    index = hashFunc(value);

    while (theArray[index] != EMPTY && theArray[index] != DELETED) {
        index++;

        // wrap when you hit the top end of the array
        if (index >= arraySize) {
            index = 0;
        }

        cout++;

        theArray[index] = value
    }

}

bool StringHash::findItem(int value) {

}

void StringHash::removeItem(int value) {

}

string StringHash::displayTable() {
    return "string";
}