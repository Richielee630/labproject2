#include "queue.h"

part2::queue::queue() {
    head = nullptr;
    tail = nullptr;
}

part2::queue &part2::queue::operator=(const part2::queue &RHS) {
    if(this == &RHS)return *this;
    if(RHS.head == RHS.tail && RHS.head == nullptr){head=tail= nullptr; return *this;}

    auto copy_runner = RHS.head;
    while(copy_runner){
        this->enque(copy_runner->data);
        copy_runner = copy_runner->next;
    }
    return *this;
}

part2::queue::~queue() {
    while(head){
        deque();
    }
}

void part2::queue::enque(std::string to_enque) {
    auto node_to_enque = new node(to_enque);
    if(is_empty()){
        head = node_to_enque;
        tail = node_to_enque;
    }
    else{
        tail->next = node_to_enque;
        tail = node_to_enque;
    }
}



void part2::queue::deque() {
    if(!is_empty()){
        auto temp = head;
        if(head != tail){
            head = head->next;
        }
        else{
            head = nullptr;
            tail = nullptr;
        }
        delete temp;
    }
}

std::string part2::queue::front() {
    return head->data;
}

bool part2::queue::is_empty() {
    return ( head == tail && head == nullptr );
}
