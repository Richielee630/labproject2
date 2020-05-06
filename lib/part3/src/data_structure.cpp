#include "data_structure.h"
#include <string>
#include <sstream>
#include <iostream>
data_structure::data_structure():head(new node(0,0)) {
    // Default constructor: Generate an empty data structure
}

data_structure::data_structure(std::string input_string):head(new node(0,0)) {
    // String constructor: Construct a data structure and store the input string into it
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
    // Default Destructor: Deconstruct the data structure
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
    // Return the number of times the integer is in the data structure.
    node *find = findnode(input_character);
    if(find) return find->count;
    return 0;
}

int data_structure::most_frequent() {
    // Return the most frequent number in the data structure. If there is more than one, return the highest value
    node* find = head->next;
    if(find) return find->value;
    return 0;

}

int data_structure::least_frequent() {
    // Return the least frequent number in the data structure. If there is more than one, return the lowest value
    node* find = head->next;
    while(find && find->next){
        find = find->next;
    }
    if(find) return find->value;
    return 0;
}

void data_structure::sort() {
    // Sort the data structure first by frequency, greatest to least and then by value, least to greatest.
    // Example: 1:3,42:4,17:3,11:1,46:1,3:2         sorted: 42:4,1:3,17:3,3:2,11:1,46:1
    return;
}

std::istream &operator>>(std::istream &stream, data_structure &structure) {
    // Stream in a string, empty the current structure and create a new structure with the new streamed in string.
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
    // Stream out the data structure
    // Output in this format "<integer>:<frequency>,<integer>:<frequency>,<integer>:<frequency>"
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
