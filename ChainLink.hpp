#pragma once

#include <string>

class ChainLink {
    public:
        ChainLink(std::string color) {
            this->color = color;
        }
        std::string get_color() {
            return this->color;
        }
    private:
        std::string color;
};
