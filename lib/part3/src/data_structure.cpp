#include "data_structure.h"
#include <string>
#include <sstream>
#include <iostream>
data_structure::data_structure():head(new node(0,0)) {
}

data_structure::data_structure(std::string input_string):head(new node(0,0)) {
    size_t pos = 0;
    size_t pre = 0;
    while(pos <= input_string.length()){
        if(pos == input_string.length() || input_string[pos] == ','){
            int value = std::stoi(input_string.substr(pre,pos-pre));
            node* find = findnode(value);
            if(find == nullptr){
                find = new node(value, 0);
                find->next = head->next;
                head->next = find;
            }
            find->count += 1;
            node* prev = findprev(find);
            prev->next = find->next;
            find->next = head->next;
            head->next = find;
            prev = head;
            while(find->next){
                if(find->count < find->next->count
                   || (find->count == find->next->count
                       && find->value > find->next->value) ){
                    prev->next = find->next;
                    find->next = find->next->next;
                    prev       = prev->next;
                    prev->next = find;
                }else{
                    break;
                }
            }
            pre = pos + 1;
        }
        ++pos;
    }
}

data_structure::~data_structure() {
    node *next = head;
    while(next){
        node *cur = next->next;
        delete next;
        next = cur;
    }
}

data_structure::node* data_structure::findnode(int value){
    node *next = head->next;
    while(next != nullptr){
        if(next->value == value){
            return next;
        }
        next = next->next;
    }
    return nullptr;
}

data_structure::node* data_structure::findprev(node *find){
    node *next = head;
    while(next->next){
        if(next->next == find){
            return next;
        }
        next = next->next;
    }
    return nullptr;
}

unsigned int data_structure::frequency(int input_character) {
    node *find = findnode(input_character);
    if(find) return find->count;
    return 0;
}

int data_structure::most_frequent() {
    node* find = head->next;
    if(find) return find->value;
    return 0;

}

int data_structure::least_frequent() {
    node* find = head->next;
    while(find && find->next){
        find = find->next;
    }
    if(find) return find->value;
    return 0;
}

void data_structure::sort() {
    return;
}

std::istream &operator>>(std::istream &stream, data_structure &structure) {
    std::string input_string;
    char buffer[4096];
    while(stream.read(buffer,sizeof(buffer))){
        input_string.append(buffer,sizeof(buffer));
    }
    std::cout << input_string << std::endl;
    data_structure::node *find = structure.head->next;
    structure.head->next = nullptr;
    while(find){
        data_structure::node* cur = find->next;
        delete find;
        find = cur;
    }
    size_t pos = 0;
    size_t pre = 0;
    while(pos <= input_string.length()){
        if(pos == input_string.length() || input_string[pos] == ','){
            int value = std::stoi(input_string.substr(pre,pos-pre));
            data_structure::node* find = structure.findnode(value);
            if(find == nullptr){
                find = new data_structure::node(value, 0);
                find->next = structure.head->next;
                structure.head->next = find;
            }
            find->count += 1;
            data_structure::node* prev = structure.findprev(find);
            prev->next = find->next;
            find->next = structure.head->next;
            structure.head->next = find;
            prev = structure.head;

            while(find->next){
                if(find->count < find->next->count
                   || (find->count == find->next->count
                       && find->value > find->next->value)){
                    prev->next = find->next;
                    find->next = find->next->next;
                    prev       = prev->next;
                    prev->next = find;
                }else{
                    break;
                }
            }
            pre = pos + 1;
        }
        ++pos;
    }

    return stream;
}

std::ostream &operator<<(std::ostream &stream, const data_structure &structure) {
    data_structure::node* find = structure.head->next;
    while(find){
        stream << std::to_string(find->value) << ":" << std::to_string(find->count);
        if(find->next){
            stream << ",";
        }
        find = find->next;
    }
    return stream;
}
