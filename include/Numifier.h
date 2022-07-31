#ifndef NUMIFIER_H
#define NUMIFIER_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "languages.h"
namespace numifier
{
    static std::map<int, std::map<std::string, int>> lookup = {

        {
            numifier::LANGUAGE::ENGLISH,
            {
                {"one", 1},
                {"two", 2},
                {"three", 3},
                {"four", 4},
                {"five", 5},
                {"six", 6},
                {"seven", 7},
                {"eight", 8},
                {"nine", 9},
                {"ten", 10},
                {"eleven", 11},
                {"twelve", 12},
                {"thirteen", 13},
                {"fourteen", 14},
                {"fifhteen", 15},
                {"sixteen", 16},
                {"seventeen", 17},
                {"eighteen", 18},
                {"nineteen", 19},
                {"twenty", 20},
                {"thirty", 30},
                {"fourty", 40},
                {"fifty", 50},
                {"sixty", 60},
                {"seventy", 70},
                {"eighty", 80},
                {"ninety", 90},
                {"hundred", 100},
                {"thousand", 1000},
                {"million", 1000000},
            },
        },
        {
            numifier::LANGUAGE::ROMAN_NUMERALS,
            {
                {"I", 1},
                {"V", 5},
                {"X", 10},
                {"L", 50},
                {"C", 100},
                {"D", 500},
                {"M", 1000},
            },
        },

        {
            numifier::LANGUAGE::HUNGARIAN,
            {

                {"egy", 1},
                {"kettő", 2},
                {"két", 2},
                {"három", 3},
                {"négy", 4},
                {"öt", 5},
                {"hat", 6},
                {"hét", 7},
                {"nyolc", 8},
                {"kilenc", 9},
                {"tíz", 10},
                {"tizen", 10},
                {"huszon", 20},
                {"harminc", 30},
                {"negyven", 40},
                {"ötven", 50},
                {"hatvan", 60},
                {"hetven", 70},
                {"nyolcvan", 80},
                {"kilencven", 90},
                {"száz", 100},
                {"ezer", 1000},
                {"millió", 1000000},

            },
        },
    };

 
    class WordParser
    {
    private:
        
        std::vector<int> segmentateString(std::string &number, numifier::LANGUAGE lang);
        int constructNumber(std::vector<int> &vec, int start, int end, numifier::LANGUAGE lang);
        int possibleRoots(std::string &buff, numifier::LANGUAGE lang);

    public:
        int parseNumber(std::string &number,numifier::LANGUAGE lang=numifier::LANGUAGE::ENGLISH);
        
    };

    

}
#endif