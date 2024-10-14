#include <gtest/gtest.h>
#include "functions.h"
#include <stdexcept>

// valid incoming data

TEST(EvaluateTest, ValidExpressions)
{
    int result;

    EXPECT_TRUE(evaluate("1 + 3", result));
    EXPECT_EQ(result, 4);

    EXPECT_TRUE(evaluate("-9 + (1 + 3) * 2", result));
    EXPECT_EQ(result, -10);

    EXPECT_TRUE(evaluate("(1 + 3) * 2", result));
    EXPECT_EQ(result, 8);

    EXPECT_TRUE(evaluate("(4 / 2) + 6", result));
    EXPECT_EQ(result, 8);

    EXPECT_TRUE(evaluate("4 + (12 / (1 * 2))", result));
    EXPECT_EQ(result, 10);

    EXPECT_TRUE(evaluate("(5+3)", result));
    EXPECT_EQ(result, 8);

    EXPECT_TRUE(evaluate("((5+3)*(2-1))", result));
    EXPECT_EQ(result, 8);

    EXPECT_TRUE(evaluate("876 + (48 * (55 * (9 / 3)))", result));
    EXPECT_EQ(result, 8796);
}

// expressions with incorrect parentheses
TEST(EvaluateTest, InvalidParentheses)
{
    int result;
    EXPECT_FALSE(evaluate("", result));
    EXPECT_FALSE(evaluate("8+", result));
    EXPECT_FALSE(evaluate("*8 )", result));
    EXPECT_FALSE(evaluate("(8", result));
    EXPECT_FALSE(evaluate("((8 (6)", result));
    EXPECT_FALSE(evaluate("8)", result));
    EXPECT_FALSE(evaluate("876) + (48 * 8)", result));
    EXPECT_FALSE(evaluate("876 + (48 * (55 * (9 / 3))", result));
    EXPECT_FALSE(evaluate("((5+3)*(2-1)", result));     // An extra open parenthesis
    EXPECT_FALSE(evaluate("((5+3))((*(2-1))", result)); // An extra closed parenthesis
}

// invalid characters
TEST(EvaluateTest, InvalidCharacters)
{
    int result;
    EXPECT_FALSE(evaluate("5 + 3 + @", result)); // Invalid character
}

// invalid characters
TEST(EvaluateTest, InvalidOperator)
{
    int result;
    EXPECT_FALSE(evaluate("5 , 3 @ 8", result)); // Invalid character
}

// division by zero
TEST(EvaluateTest, DivisionByZero)
{
    int result;
    const char *expression = "10 / 0"; // Exeption
    EXPECT_THROW({ evaluate(expression, result); }, std::runtime_error);
}

// run tests
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
