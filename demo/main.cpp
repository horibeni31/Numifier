#include <iostream>
#include <string>

#include "numifier.h"
int main()
{
    std::string input;
    std::cout << "Enter a number: ";
    std::getline(std::cin, input);
    numifier::WordParser wp;
    auto number = wp.parseNumber(input);
    if (number.has_value())

        std::cout << "result: " << number.value() << std::endl;
    else
        std::cout << "parse error"<< std::endl;

    return 0;
}