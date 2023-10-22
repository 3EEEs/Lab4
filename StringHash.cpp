//
// Created by Student on 10/19/2023.
//

#include "StringHash.hpp"

//Helper Functions
int StringHash::hashFunc(int key) {
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
StringHash::StringHash(): head(nullptr), tail(nullptr), lastFoundNode(nullptr) {
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