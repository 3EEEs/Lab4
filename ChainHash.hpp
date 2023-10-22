//
// Created by Ethan Short on 10/22/23.
//

#ifndef LAB4_CHAINHASH_HPP
#define LAB4_CHAINHASH_HPP

class ChainHash {
    char value;
    ChainHash* next;
    ChainHash* prev;

public:
// constructor
    explicit ChainHash(int value, ChainHash* next = nullptr, ChainHash* prev = nullptr) {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }

// access methods
    int getValue() const {
        return this->value;
    }

    ChainHash* getNext() {
        return this->next;
    }

    ChainHash* getPrev() {
        return this->prev;
    }

    void setNext(ChainHash* next) {
        this->next = next;
    }

    void setPrev(ChainHash* prev) {
        this->prev = prev;
    }
};

#endif //LAB4_CHAINHASH_HPP
