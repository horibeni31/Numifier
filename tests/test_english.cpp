#include "numifier.h"

bool testcase(const std::string& literal, int result)
{
    numifier::WordParser parser;
    auto a = parser.parseNumber(literal);
    if (a.has_value() && a.value() == result)
    {
        printf("passed test <%s> \n", literal.c_str());
        return true;
    }
    else
    {
        if (a.has_value())
            printf("failed test <%s>: expected: %d got: %d \n", literal.c_str(), result, a.value());
        else
            printf("failed test <%s>: could't parese input\n", literal.c_str());
        return false;
    }
}

bool test_Trivial()
{
    // clang-format off
    return 
    testcase("one", 1)&&
    testcase("two", 2)&&
    testcase("three", 3)&&
    testcase("four", 4)&&
    testcase("five",5)&&
    testcase("six", 6)&&
    testcase("seven",7)&&
    testcase("eight", 8)&&
    testcase("nine", 9)&&
    testcase("ten", 10)&&
    testcase("eleven", 11)&&
    testcase("twelve", 12)&&
    testcase("thirteen", 13)&&
    testcase("fourteen", 14)&&
    testcase("fifhteen", 15)&&
    testcase("sixteen", 16)&&
    testcase("seventeen", 17)&&
    testcase("eighteen", 18)&&
    testcase("nineteen", 19)&&
    testcase("twenty", 20)&&
    testcase("hundred", 100)&&
    testcase("thousand", 1000)&&
    testcase("million", 1000000);
    // clang-format on
}
int main()
{
    return test_Trivial()?0:1;
}