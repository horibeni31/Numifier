#include "numifier.h"

int numifier::WordParser::constructNumber(std::vector<int> &vec, int start, int end, numifier::LANGUAGE lang)
{
    int max = start;
    for (size_t i = start + 1; i < end; i++)
    {
        if (vec[i] > vec[max])
            max = i;
    }
    if (lang == numifier::LANGUAGE::ROMAN_NUMERALS)
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
int numifier::WordParser::possibleRoots(std::string &buff, numifier::LANGUAGE lang)
{
    int c = 0;
    for (auto const &x : lookup[lang])
    {
        if (x.first.rfind(buff, 0) == 0)
            c++;
    }
    return c;
}
std::vector<int> numifier::WordParser::segmentateString(const std::string &number, numifier::LANGUAGE lang)
{
    int i = 0;
    std::string buffer = "";  // todo stringbuilder
    std::vector<int> segments;
    while (i < number.length())
    {
        buffer += number[i];
        if (lookup[lang].count(buffer) == 1)
        {
            if (possibleRoots(buffer, lang) == 1)
            {
                segments.push_back(lookup[lang][buffer]);
                buffer = "";
            }
            else if (possibleRoots(buffer, lang) > 1)  // pl öt és ötven nél
            {
                if (i < number.length() - 1)
                {
                    std::string temp = buffer + number[i + 1];
                    if (possibleRoots(temp, lang) == 0)
                    {
                        segments.push_back(lookup[lang][buffer]);
                        buffer = "";
                    }
                    else
                    {
                        // a buffer még nem a teljes gyököt tartalmazza
                    }
                }
                else
                {
                    segments.push_back(lookup[lang][buffer]);
                    buffer = "";
                }
            }
        }
        i++;
    }
    return segments;
}

int numifier::WordParser::parseNumber(std::string &number, numifier::LANGUAGE lang)
{
    std::vector<int> segments = segmentateString(number, lang);

    if (segments.size() == 0)
    {
        return -1;
    }
    int num = constructNumber(segments, 0, segments.size(), lang);
    return num;
}
