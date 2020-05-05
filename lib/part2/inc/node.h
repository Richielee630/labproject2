#ifndef CMPE126EXAM1_TUESDAY_NODE_H
#define CMPE126EXAM1_TUESDAY_NODE_H

#include <string>

namespace part2{
    class node{
    public:
        node* next;
        std::string data;
        explicit node(const std::string &data) :
                data(data), next(nullptr){};
    };
}

#endif
