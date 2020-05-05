#ifndef CMPE126EXAM1_TUESDAY_STACK_H
#define CMPE126EXAM1_TUESDAY_STACK_H

#include "node.h"

namespace part2{
    class stack{
        node* head;
    public:
        stack();
        ~stack();

        void push(std::string to_push);
        void pop();
        std::string top();

        bool is_empty();
    };
}

#endif

