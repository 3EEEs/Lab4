//
// Created by Ethan Short on 10/22/23.
//

#include "ChainHash.hpp"

ChainHash::ChainHash() {
    if (arraySize > defaultSize) {
        this->arraySize = defaultSize;
    } else {
        this->arraySize = arraySize;
    }

    this->head = new ChainLink(); // maybe

}

//Add more
ChainHash::~ChainHash() {
    delete this->head;
}

int ChainHash::hash(int value) {
    return value % arraySize;
}