#include <cctype>
#include <iostream>
#include <stack>
#include <stdexcept>

#include "functions.h"

int operation(int val1, int val2, char op)
{
    switch (op)
    {
    case '+':
        return val1 + val2;
    case '-':
        return val1 - val2;
    case '*':
        return val1 * val2;
    case '/':
        if (val2 == 0)
        {
            throw std::runtime_error("Division by zero!");
        }
        return val1 / val2;
    default:
        throw std::runtime_error("Invalid operation!");
    }
}

bool calc_from_stack(std::stack<int> &value, std::stack<char> &oper)
{
    if (value.size() < 2)
    {
        std::cerr << "Error: insufficient values for calculation.\n";
        return false;
    }

    int const val2 = value.top();
    value.pop();
    int const val1 = value.top();
    value.pop();
    char const op = oper.top();
    oper.pop();

    if (op == '(')
    {
        std::cerr << "Extra opening parenthesis found!" << std::endl;
        return false;
    }
    const int calc_result = operation(val1, val2, op);
    std::cout << "Calculate: " << val1 << " " << op << " " << val2 << " = " << calc_result << std::endl;
    value.push(calc_result);

    return true;
}

bool calc_inside_brackets(std::stack<int> &value, std::stack<char> &oper)
{
    while (!oper.empty() && oper.top() != '(')
    {
        if (!calc_from_stack(value, oper))
        {
            return false;
        }
    }
    return true;
}

// Функція, яка виконує обчислення з урахуванням пріоритетів
bool evaluate(const char *expression, int &result)
{

    std::stack<int> value; // stack for numbers
    std::stack<char> oper; // stack for operators

    int parenthesis_count = 0;    // validator of parenthesis
    bool expecting_number = true; // checking unary minus

    while (*expression != 0)
    {
        // skip spaces
        if (*expression == ' ')
        {
            expression++;
            continue;
        }

        // if number, read number from symbols
        if (isdigit(*expression) != 0)
        {
            int number = 0;
            while (isdigit(*expression) != 0)
            {
                number = (number * 10) + (*expression - '0'); // from letters to numbers
                expression++;
            }
            std::cout << "Number was read: " << number << std::endl;
            value.push(number);
            expecting_number = false;
        }
        // open parenthesis add to the operator stack
        else if (*expression == '(')
        {
            parenthesis_count++;
            oper.push(*expression);
            expression++;
            expecting_number = true;
        }
        // closed parenthesis calculate everything inside
        else if (*expression == ')')
        {
            // If parenthesis_count goes negative, we have an unmatched closing parenthesis
            parenthesis_count--;
            if (parenthesis_count < 0)
            {
                std::cerr << "Error: Extra closing parenthesis found!\n";
                return false;
            }
            // calculate inside ( )
            if(!calc_inside_brackets(value,oper))
            {
                return false;
            }

            // Ensure the corresponding '(' is popped
            if (!oper.empty())
            {
                oper.pop();
            }
            expression++;
            expecting_number = false;
        }
        // perator (+, -, *, /)
        else if (*expression == '/' || *expression == '*' || *expression == '+' || *expression == '-')
        {
            if (*expression == '-' && expecting_number)
            {
                expression++; // pass minus
                int number = 0;
                while (isdigit(*expression) != 0)
                {
                    number = (number * 10) + (*expression - '0');
                    expression++;
                }
                std::cout << "A unary number has been read: " << -number << std::endl;
                value.push(-number);
                expecting_number = false;
                continue;
            }

            if(!calc_inside_brackets(value,oper))
            {
                return false;
            }
           
            oper.push(*expression);
            expression++;
            expecting_number = true;
        }
        else
        {
            std::cerr << "Unknown symbol" << std::endl;
            return false;
        }
    }

    // Complete left operations
    while (!oper.empty())
    {
        if (!calc_from_stack(value, oper))
        {
            return false;
        }
    }

    // Перевіряємо, що стек правильно містить результат
    if (value.size() == 1)
    {
        result = value.top();
        return true;
    }

    std::cerr << "Error: incorrect final result stack state.\n";
    return false;
}

