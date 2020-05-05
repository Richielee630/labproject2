#ifndef CMPE126EXAM1_TUESDAY_QUEUE_H
#define CMPE126EXAM1_TUESDAY_QUEUE_H

#include "node.h"

namespace part2{
    class queue{
    private:
        node* head;
        node* tail;
    public:
        queue();
        queue &operator=(const queue &RHS);
        ~queue();

        void enque(std::string to_enque);
        void deque();
        std::string front();

        bool is_empty();
    };
}

#endif
