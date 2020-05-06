#ifndef EXAM_3_DATA_STRUCTURE_H
#define EXAM_3_DATA_STRUCTURE_H
#include <string>
#include <ostream>

class data_structure
{
private:
    typedef struct node{
        int value;
        unsigned int count;
        node* next;
        node(int v, unsigned int c):value(v),count(c),next(nullptr){}
    }node;
    node* head;
    node* findnode(int value);
    node* findprev(node *find);
public:
    data_structure();  // Default constructor
    explicit data_structure(std::string input_string); // String constructor
    ~data_structure(); // Default destructor

    void sort(); // Sort the data structure first by frequency, greatest to least and then by character value, least to greatest.
    int most_frequent(); // Return the most frequent number in the data structure. If there is more than one, return the highest value (maximum)
    int least_frequent(); // Return the least frequent number in the data structure. If there is more than one, return the lowest value (minimum)
    unsigned int frequency(int input_character); // Return the number of times the integer is in the data structure.

    friend std::ostream &operator<<(std::ostream &stream, const data_structure &structure);// Stream Insertion
    friend std::istream &operator>>(std::istream &stream, data_structure &structure); // Stream Extraction
};


#endif //EXAM_3_DATA_STRUCTURE_H
