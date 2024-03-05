#include "numifier.h"

#include <algorithm>
#include <regex>

#include "languages.h"
int numifier::WordParser::constructNumber(std::vector<int> &vec, int start, int end, numifier::Language lang)
{
    int max = start;
    for (size_t i = start + 1; i < end; i++)
    {
        if (vec[i] > vec[max])
            max = i;
    }
        if (lang == numifier::Language::ROMAN_NUMERALS)
    {
                int left = start == max ? 0 : constructNumber(vec, start, max, lang);
        int right = end - 1 == max ? 0 : constructNumber(vec, max + 1, end, lang);
        return vec[max] - left + right;
    }
    else
    {
        int left = start == max ? 1 : constructNumber(vec, start, max, lang);
        int right = end - 1 == max ? 0 : constructNumber(vec, max + 1, end, lang);
        return vec[max] * left + right;
    }
}
int numifier::WordParser::possibleRoots(std::string &buff, numifier::Language lang)
{
    int c = 0;
    for (auto const &x : languages[lang].dictionary)
    {
        if (x.first.rfind(buff, 0) == 0)
            c++;
    }
    return c;
}
std::vector<int> numifier::WordParser::segmentateString(const std::string &number, numifier::Language lang)
{
    int i = 0;
    std::string buffer = "";  // todo stringbuilder
    std::vector<int> segments;
    while (i < number.length())
    {
        buffer += number[i];
        if (languages[lang].dictionary.count(buffer) == 1)
        {
            if (possibleRoots(buffer, lang) == 1)
            {
                segments.push_back(languages[lang].dictionary[buffer]);
                buffer = "";
            }
            else if (possibleRoots(buffer, lang) > 1)  // pl öt és ötven nél
            {
                if (i < number.length() - 1)
                {
                    std::string temp = buffer + number[i + 1];
                    if (possibleRoots(temp, lang) == 0)
                    {
                        segments.push_back(languages[lang].dictionary[buffer]);
                        buffer = "";
                    }
                    else
                    {
                        // a buffer még nem a teljes gyököt tartalmazza
                    }
                }
                else
                {
                    segments.push_back(languages[lang].dictionary[buffer]);
                    buffer = "";
                }
            }
        }
        i++;
    }
    return segments;
}
std::string numifier::WordParser::preprocessString(const std::string &str, numifier::Language lang)
{
    std::string ret = str;
    for (int i = 0; i < languages[lang].separators.size(); i++)
    {
        std::regex sep(languages[lang].separators[i]);
        ret = regex_replace(ret, sep, "");
    }
    return ret;
}

std::optional<int> numifier::WordParser::parseNumber(const std::string &number, numifier::Language lang)
{
    std::string preprocessed = preprocessString(number, lang);
    std::vector<int> segments = segmentateString(preprocessed, lang);

    if (segments.size() == 0)
    {
        return {};
    }
    int num = constructNumber(segments, 0, segments.size(), lang);
    return num;
}
