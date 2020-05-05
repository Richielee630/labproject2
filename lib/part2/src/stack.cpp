#include "stack.h"

part2::stack::stack() {
    head = nullptr;
}

part2::stack::~stack() {
    while(head){
        pop();
    }
}

void part2::stack::push(std::string to_push) {
    auto node_to_push = new node(to_push);
    node_to_push->next = head;
    head = node_to_push;
}

void part2::stack::pop() {
    if(!is_empty()){
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

std::string part2::stack::top() {
    return head->data;
}

bool part2::stack::is_empty() {
    return head == nullptr;
}
