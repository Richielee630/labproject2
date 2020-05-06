#include "gtest/gtest.h"
#include "calculator.h"

TEST(Part2, simple_test) {
    part2::calculator* calculator_UT;
    std::string input = "1 + 2 + 3 - 3 - 2 - 1";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(0,calculator_UT->calculate());

    delete calculator_UT;
    input = "1 * 2 * 3 / 3 / 2 / 1";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(1,calculator_UT->calculate());

    delete calculator_UT;
    input = "2 * 3 + 5 - 1";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(10,calculator_UT->calculate());

    delete calculator_UT;
    input = "11 + 22 + 33 - 33 - 22 - 11";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(0,calculator_UT->calculate());

    delete calculator_UT;
    input = "11 * 22 * 33 / 33 / 22 / 11";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(1,calculator_UT->calculate());

    delete calculator_UT;
    input = "2 * 30 + 54 - 1";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(113,calculator_UT->calculate());
    delete calculator_UT;
}

TEST(Part2, big_tests) {
    part2::calculator* calculator_UT;
    std::string input = "271 + 32 * ( 91 - 1 ) + 14 / 2";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(3158,calculator_UT->calculate());

    delete calculator_UT;
    input = "49 * ( 17 * ( 3 + 2 * ( 12 + 2 * ( 45 - 43 ) + 2 ) ) + 1 * ( 6 / 2 ) )";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(32634,calculator_UT->calculate());

    delete calculator_UT;
    input = "( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + ( 1 + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 ) + 1 )";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(20,calculator_UT->calculate());
    delete calculator_UT;
}

TEST(Part2, factorial_simple){
    part2::calculator* calculator_UT;
    std::string input = "5 !";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(120, calculator_UT->calculate());
    std::string expected_postfix = "5 !";
    EXPECT_EQ(expected_postfix, calculator_UT->postfix());
    delete calculator_UT;

    input = "0 !";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(1, calculator_UT->calculate());
    expected_postfix = "0 !";
    EXPECT_EQ(expected_postfix, calculator_UT->postfix());
    delete calculator_UT;
}

TEST(Part2, factorial_complicated){
    part2::calculator* calculator_UT;
    std::string input = "( 2 + 1 ) ! - 4";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(2, calculator_UT->calculate());

    std::string expected_postfix = "2 1 + ! 4 -";
    EXPECT_EQ(expected_postfix, calculator_UT->postfix());
    delete calculator_UT;

    input = "( 3 ! ) + ( 2 ! * 2 ) ^ 2";
    calculator_UT = new part2::calculator(input);

    EXPECT_EQ(22, calculator_UT->calculate());

    expected_postfix = "3 ! 2 ! 2 * 2 ^ +";
    EXPECT_EQ(expected_postfix, calculator_UT->postfix());
    delete calculator_UT;
}