#include "numifier.h"

int main() {
    numifier::WordParser parser;
    std::string str = "one";
    int a = parser.parseNumber(str);

 return a != 1;
}