#pragma once

#include "ChainLink.hpp"
#include <iostream>
using namespace std;

class Chain {
    public:
        Chain(ChainLink *chainlink) {
            this->chainlink = chainlink;
        }

        Chain(ChainLink *chainlink, Chain *prevLink) {
            this->chainlink = chainlink;

            this->dnLink = prevLink;
            prevLink->upLink = this;
        }

        Chain next() {
            if (this->upLink == nullptr) {
                cout << "This is the end of the list." << endl;
                return nullptr;
            }
            return *(this->upLink);
        }

        Chain prev() {
            if (this->dnLink == nullptr) {
                cout << "This is the start of the list." << endl;
                return nullptr;
            }
            return *(this->dnLink);
        }

        ChainLink data() {
            return *(this->chainlink);
        }

        int size() {
            int count = 0;
            if (upLink != nullptr){
                count = this->upLink->size(1);
            }
            return count;
        }

        void append(Chain *newLink) { // This sets a new tail
            if (upLink == nullptr) {
                this->upLink = newLink;
                newLink->dnLink = this;
            }
            else {
                upLink->append(newLink);
            }
        }

        void prepend(Chain *newLink) { // This sets a new head
            if (dnLink == nullptr) {
                newLink->upLink = this;
                this->dnLink = newLink;
            }
            else {
                dnLink->prepend(newLink);
            }
        }


    private:
        int size(int count) {
            if (upLink != nullptr){
                count++;
                count = this->upLink->size(count);
            }
            return count;
        }
        ChainLink *chainlink = nullptr;
        Chain *upLink = nullptr;
        Chain *dnLink = nullptr;
};