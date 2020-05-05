#include "calculator.h"
#include "stack.h"
#include <sstream>
#include <vector>
#include <iterator>
#include <math.h>

bool is_number(std::string input_string);
bool is_operator(std::string input_string);
int operator_priority(std::string operator_in);
int calc_binary_operation(int lhs, int rhs, std::string op);

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

void part2::calculator::parse_to_infix(std::string &input_string) {
    std::vector<std::string> parsed_tokens = split(input_string, ' ');
    for(std::string &item:parsed_tokens){
        infix_expression.enque(item);
    }
}

void part2::calculator::convert_to_postfix() {
    stack op_stack;

    queue infix_queue;
    infix_queue = infix_expression;

    while(!infix_queue.is_empty()){
        std::string current_token = infix_queue.front();
        infix_queue.deque();

        if(is_number(current_token)) postfix_expression.enque(current_token);
        else if (is_operator(current_token)){
            while (!op_stack.is_empty() && operator_priority(op_stack.top()) >= operator_priority(current_token) && op_stack.top() != "(") {
                postfix_expression.enque(op_stack.top());
                op_stack.pop();
            }
            op_stack.push(current_token);
        }
        else if(current_token == "(")
            op_stack.push(current_token);
        else if (current_token == ")") {
            while (op_stack.top() !=
                   "(") {
                postfix_expression.enque(op_stack.top());
                op_stack.pop();
            }
            op_stack.pop();
        }
    }
    while(!op_stack.is_empty()) {
        if (op_stack.top() == "(") throw "mismatched parenthesis";
        postfix_expression.enque(op_stack.top());
        op_stack.pop();
    }
}

part2::calculator::calculator(std::string &input_string) {
    parse_to_infix(input_string);
    convert_to_postfix();
}

part2::calculator::~calculator(){
    infix_expression.~queue();
    postfix_expression.~queue();
}



int part2::calculator::calculate() {
    stack calc_stack;
    queue calc_queue;
    calc_queue = postfix_expression;
    int left, right;
    std::string op;

    while(!calc_queue.is_empty()){
        while(is_number(calc_queue.front())){
            calc_stack.push(calc_queue.front());
            calc_queue.deque();
        }
        op = calc_queue.front();
        calc_queue.deque();

        right = stoi(calc_stack.top());
        calc_stack.pop();
        left = stoi(calc_stack.top());
        calc_stack.pop();

        std::string result = std::to_string(calc_binary_operation(left, right, op));
        calc_stack.push(result);
    }
    return stoi(calc_stack.top());
}

std::string part2::calculator::postfix() {
    queue to_string_queue;
    to_string_queue = postfix_expression;
    std::string to_return;
    while(!to_string_queue.is_empty()){
        std::string item = to_string_queue.front();
        to_string_queue.deque();
        to_return += item;
        if(!to_string_queue.is_empty()) to_return += " ";
    }
    return to_return;
}

bool is_number(std::string input_string){
    std::string::iterator location = input_string.begin();
    if(*location >= '0' && *location <= '9') return true;
    if(*location != '-')return false;
    return(*++location >='0' && *location <= '9');
}

bool is_operator(std::string input_string){
    std::string::iterator location = input_string.begin();
    if(*location == '+' || *location == '*' || *location == '/' || *location == '^') return true;
    return (*location == '-' && (location+1) == input_string.end());
}

int operator_priority(std::string operator_in){
    std::string::iterator location = operator_in.begin();
    switch (*location){
        case '^': return 4;
        case '*': return 3;
        case '/': return 3;
        case '+': return 2;
        case '-': return 2;
        default: return -1;
    }
}


int calc_binary_operation(int lhs, int rhs, std::string op){
    std::string::iterator op_iter = op.begin();
    switch (*op_iter){
        case '^': return (int)pow(lhs, rhs);
        case '*': return lhs * rhs;
        case '/': return lhs / rhs;
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        default: throw "unknown operator";
    }
}