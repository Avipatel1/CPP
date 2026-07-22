#include <cstdint>
#include <iostream>

/*
Write the following program: The user is asked to enter 2 floating point numbers (use doubles).
The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. 
The program computes the answer on the two numbers the user entered and prints the results.
If the user enters an invalid symbol, the program should print nothing.

Example of program:

Enter a double value: 6.2
Enter a double value: 5
Enter +, -, *, or /: *
6.2 * 5 is 31
*/
double getNumber();
char getOperator();
void printResult(double first, double second, char op);


int main()
{
    double first{getNumber()};
    double second{getNumber()};
    char op{getOperator()};

    printResult(first, second, op);
    return 0;
}

double getNumber()
{
    std::cout << "Enter a number: ";
    double number{};
    std::cin >> number;
    return number;
}

char getOperator()
{
    std::cout << "Enter an operator (+, -, *, /): ";
    char op{};
    std::cin >> op;
    return op;
}

void printResult(double first, double second, char op)
{
    double result{};
    if (op == '+')
    {
        result = first + second;
        std::cout << first << " + " << second << " = " << result << std::endl;
    }
    else if (op == '-')
    {
        result = first - second;
        std::cout << first << " - " << second << " = " << result << std::endl;
    }
    else if (op == '*')
    {
        result = first * second;
        std::cout << first << " * " << second << " = " << result << std::endl;
    }
    else if (op == '/')
    {
        if (second == 0)
        {
            std::cout << "Error: Division by zero is not allowed." << std::endl;
            return;
        }
        result = first / second;
        std::cout << first << " / " << second << " = " << result << std::endl;
    }
    else
    {
        std::cout << "Error: Invalid operator" << std::endl;
    }
}