#ifndef NUMIFIER_H
#define NUMIFIER_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "languages.h"
#include <optional>

namespace numifier
{
    
    class WordParser
    {
    private:
        std::string preprocessString(const std::string& str,numifier::Language lang);
        std::vector<int> segmentateString(const std::string &number, numifier::Language lang);
        int constructNumber(std::vector<int> &vec, int start, int end, numifier::Language lang);
        int possibleRoots(std::string &buff, numifier::Language lang);

    public:
        std::optional<int> parseNumber(const std::string &number,numifier::Language lang=numifier::Language::ENGLISH);
        
    };

    

}
#endif