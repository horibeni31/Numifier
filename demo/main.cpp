#include <iostream>
#include "numifier.h"
int main()
{
    std::string input;
    std::cout<<"Enter a number: ";
    std::cin>>input;
    numifier::WordParser wp;
   int number =  wp.parseNumber(input);

    std::cout<<"result: "<<number<<std::endl;

    return 0;
}