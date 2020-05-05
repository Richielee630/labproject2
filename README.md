# Lab Exam 2 #
###### Tuesday, 5 May 2020 ######

Exams that don't compile or can't run all of the submitted tests will get a zero. Comment out or disable tests that are crashing when you run the tests. To disable a test, add `DISABLED_` to the beginning of the test. Tests that are modified in your exam will not be graded. Look at how the factorial portion of the part2 tests as an example.

#### Part 1 ####
Write 3 tests to test the functions located in `test/part1_tests.cpp`. These functions test functions that score and validate board states in Tic Tac Toe. Make sure you are thorough in your testing. Feel free to rename the names of the tests to be clear on what you are testing.

#### Part 2 ####
Extend the provided calculator to support the `!` factorial operator. Renable the factorial tests to make sure that your changes work.

#### Part 3 ####
You will be creating a data structure that holds both an integer and an unsigned integer. This structure will be generated by parsing a string and inserting each of the numbers into the structure. You can **implement** any structure you want, but some structures are inherently better than others for this assignment.

Your structure needs to support the functions already provided in the template, and you can add any functions you need into the *private* section of the data structure. There should be no other public functions other than the ones provided to you.


##### Functional Specification #####
*data_structure()*: The default constructor. This should create an empty structure

*data_structure(std::string input)*: Construct a structure using the given string input

*~data_structure()*: Default destructor. Needs to delete each of the objects in the structure

*unsigned int get_frequency(int key)*: Return the number of times the integer is in the data structure. Return 0 if the number is not in the structure, because it has a frequency of 0 if it isn't in the structure.

*int most_frequent()*: Return the most frequent number in the data structure. If there is more than one, return the lowest value

*int least_frequent()*: Return the least frequent number in the data structure. If there is more than one, return the highest value

*void sort()*: Sort the data structure first by frequency, greatest to least and then by value, least to greatest.

*friend std::ostream &operator<<(std::ostream &stream, const data_structure &structure)*: Stream Insertion. Used to create a stream for printing using cout or converting into a string.

*friend std::istream &operator>>(std::istream &stream, data_structure &structure)*: Stream Extraction. Used to stream in a string and store that input into the structure. The data that was previously in the structure needs to be deleted and then the new string needs to be inserted.

#### Hints ####
- [Google Test Documentation](https://github.com/google/googletest/tree/master/googletest/docs)
- [Shunting-Yard Algorithm Wiki](https://en.wikipedia.org/wiki/Shunting-yard_algorithm)