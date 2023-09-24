#ifndef NUMIFIER_H
#define NUMIFIER_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "languages.h"


namespace numifier
{
    
    class WordParser
    {
    private:
        
        std::vector<int> segmentateString(const std::string &number, numifier::LANGUAGE lang);
        int constructNumber(std::vector<int> &vec, int start, int end, numifier::LANGUAGE lang);
        int possibleRoots(std::string &buff, numifier::LANGUAGE lang);

    public:
        int parseNumber(std::string &number,numifier::LANGUAGE lang=numifier::LANGUAGE::ENGLISH);
        
    };

    

}
#endif