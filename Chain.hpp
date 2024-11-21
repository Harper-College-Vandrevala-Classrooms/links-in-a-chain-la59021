#pragma once

#include "ChainLink.hpp"
#include <string>
using namespace std;

class Chain {
    public:
        Chain(ChainLink *chainlink) {
            this->chainlink = chainlink;
        }
        Chain(ChainLink *chainlink, Chain *link) {
            this->chainlink = chainlink;
            link->link = this;
        }
        Chain next() {
            return *(this->link);
        }
        ChainLink data() {
            return *(this->chainlink);
        }
        int size() {
            int count = 0;
            if (link != nullptr){
                count = this->link->size(1);
            }
            return count;
        }
        void push_back(Chain *newLink) {
            if (link == nullptr) {
                this->link = newLink;
            }
            else {
                link->push_back(newLink);
            }
        }
        void push_front(Chain *newLink) {
            newLink->link = this;
        }
    private:
        int size(int count) {
            if (link != nullptr){
                count++;
                count = this->next().size(count);
            }
            return count;
        }
        ChainLink *chainlink = nullptr;
        Chain *link = nullptr;
};