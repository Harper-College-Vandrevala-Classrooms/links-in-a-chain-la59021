#pragma once

#include "ChainLink.hpp"
#include <iostream>
using namespace std;

class LinkedChain {
    public:
        LinkedChain(ChainLink* chain_link) {
            this->chain_link = chain_link;
        }

        LinkedChain(ChainLink* chain_link, LinkedChain* prev_link) {
            this->chain_link = chain_link;
            this->down_link = prev_link;
            prev_link->up_link = this;
        }

        LinkedChain* next() {
            return this->up_link;
        }

        LinkedChain* prev() {
            return this->down_link;
        }

        ChainLink* data() {
            return this->chain_link;
        }

        int size() {
            int count = 0;
            if (up_link != nullptr){
                count = this->up_link->size(1);
            }
            return count;
        }

        void push_Back(LinkedChain* next_link) { // This sets a new tail
            if (this->up_link == nullptr) {
                this->up_link = next_link;
                next_link->down_link = this;
            }
            else {
                up_link->push_Back(next_link);
            }
        }

        void push_Front(LinkedChain* prev_link) { // This sets a new head
            if (this->down_link == nullptr) {
                this->down_link = prev_link;
                prev_link->up_link = this;
            }
            else {
                down_link->push_Front(prev_link);
            }
        }

        bool operator==(LinkedChain* other) { // This defines what == means
            return this == other;
        }

    private:
        int size(int count) {
            if (up_link != nullptr){
                count++;
                count = this->up_link->size(count);
            }
            return count;
        }
        ChainLink* chain_link = nullptr;
        LinkedChain* up_link = nullptr;
        LinkedChain* down_link = nullptr;
};