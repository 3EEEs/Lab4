//
// Created by Student on 10/19/2023.
//

#include "StringHash.hpp"

//Helper Functions
int StringHash::hashFunc(int key) {
        // initialize index
        int hashValue = 0;

// walk through string one char at a time
        for int i = 0; i < key.length(); i++

// multiply current sum
        hashValue *= 128

// add current character's ascii value
        hashValue += key[i]

// shrink to fit
        hashValue %= arraySize


// return the result
        return hashValue
}

StringHash::StringHash(int size) {
    if (size > defaultSize) {
        size = defaultSize;
    }

    this->size = size;
}
//test
StringHash::~StringHash() {
    delete theArray;
}

void StringHash::addItem(int value) {
    temp = new theArray[value];

    index = hashFunc(value);

    //add to the head of the list at that location
    temp->next = theArray[index];
    theArray[index] = temp;

}

bool StringHash::findItem(int value) {

}

void StringHash::removeItem(int value) {

}

string StringHash::displayTable() {
    return "string";
}