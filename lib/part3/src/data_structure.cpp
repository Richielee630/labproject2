#include "data_structure.h"
#include <string>

data_structure::data_structure() {
    // Default constructor: Generate an empty data structure

}

data_structure::data_structure(std::string input_string) {
    // String constructor: Construct a data structure and store the input string into it

}

data_structure::~data_structure() {
    // Default Destructor: Deconstruct the data structure
}

unsigned int data_structure::frequency(int input_character) {
    // Return the number of times the integer is in the data structure.
    return 0;
}

int data_structure::most_frequent() {
    // Return the most frequent number in the data structure. If there is more than one, return the highest value
    return 0;
}

int data_structure::least_frequent() {
    // Return the least frequent number in the data structure. If there is more than one, return the lowest value
    return 0;
}

void data_structure::sort() {
    // Sort the data structure first by frequency, greatest to least and then by value, least to greatest.
    // Example: 1:3,42:4,17:3,11:1,46:1,3:2         sorted: 42:4,1:3,17:3,3:2,11:1,46:1
}

std::istream &operator>>(std::istream &stream, data_structure &structure) {
    // Stream in a string, empty the current structure and create a new structure with the new streamed in string.
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const data_structure &structure) {
    // Stream out the data structure
    // Output in this format "<integer>:<frequency>,<integer>:<frequency>,<integer>:<frequency>"
    return stream;
}
