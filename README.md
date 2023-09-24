# Numifier
A  C++ library to convert numbers from word representation to numbers.

## Building with CMake 
- create a build folder and navigate to it
```
mkdir buid 
cd build
```
- build the project
```
cmake ..  
cmake --build .  
```
- You can try the library using the build/demo app

## Usage
- build the library, and link libNumifier.a with your project and include the Numifier.h header
- Create a parser object 
```
numifier::WordParser parser;
```
- Parse an std::string with 
``` 
std::string str = "fiftyonethousand";
int number = parser.parseNumber(str); //will return 51000
```
- The default language is English, but you can also parse hungarian numbers, and Roman numerals
```
int number = parser.parseNumber(str,numifier::LANGUAGE::HUNGARIAN);  
int number = parser.parseNumber(str,numifier::LANGUAGE::ROMAN_NUMERALS);
```
## The algorithm
### Step 1: Format the input string
Remove the spaces,hyphens and all the "and" words from the string
for example the string "one thousand three hundred twenty-four" will become "onethousandthreehundredtwentyfour"  
(not yet implemented)
### Step 2 Segmentate the input string

-Split the input string along the selected language's trivial numbers:  
For example the string `onethousandthreehundredtwentyfour` will become `["one","thousand","three","hundred","twenty","four"]`  
The resulting vector can be translating into an integer vector, using the language's lookup table, so the end result will be `[1,1000,3,100,20,4]`  

Currently only English, Hungarian, and Roman Numerals are supported.  

### Step 3 Construct the number 
If you splice the result array from Step2 along the maximum value, put the maximum in the root node of a binary tree, and repeat the process recursively on the left and right side of the array, and you should have a binary tree like this:
![image](https://user-images.githubusercontent.com/57011394/182153137-c3874073-0efc-469c-8dfb-da40cdac5a84.png)  
After construction the tree, with inorder-traversal multiply the root node with the left side, and add the right side, and the result should be the final parsed integer.




 
    
  
