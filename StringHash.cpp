//
// Created by Student on 10/19/2023.
//

#include "StringHash.hpp"

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

}

bool StringHash::findItem(int value) {

}

void StringHash::removeItem(int value) {

}

string StringHash::displayTable() {
    return "string";
}