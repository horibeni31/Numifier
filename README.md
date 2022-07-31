# Numifier
A  C++ library to convert numbers from word representation to numbers.
# Usage
- build the library, and link with your project
- include the Numifier.h and  
- Create a parser object 
```
numifier::WordParser parser;
```
- Parse an std::string with 
``` 
std::string str = "fiftyonethousand";
int number = parser.parseNumber(str); 
```
- The default language is English, but you can also parse hungarian numbers, and Roman numerals
```
int number = parser::parseNumber(str,numifier::LANGUAGE::HUNGARIAN);
int number = parser::parseNumber(str,numifier::LANGUAGE::ROMAN_NUMERALS);
```


 
    
  
