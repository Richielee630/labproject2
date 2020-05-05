#ifndef CMPE126EXAM1_TUESDAY_CALCULATOR_H
#define CMPE126EXAM1_TUESDAY_CALCULATOR_H

#include "queue.h"

namespace part2{
    class calculator{
    private:
        queue infix_expression;
        queue postfix_expression;

        void parse_to_infix(std::string &input_string);
        void convert_to_postfix();

    public:
        explicit calculator(std::string &input_string);
        ~calculator();
        int calculate();
        std::string postfix();
    };
}

#endif