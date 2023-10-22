//
// Created by Ethan Short on 10/22/23.
//

#ifndef LAB4_CHAINLINK_HPP
#define LAB4_CHAINLINK_HPP

class ChainLink {
private:
    int value;
    ChainLink* next;
public:


    // access methods ? might not use

    ChainLink* getNext() {
        return this->next;
    }

    void setNext(ChainLink* next) {
        this->next = next;
    }
};

#endif //LAB4_CHAINLINK_HPP
