# Numifier
A  C++ library to convert numbers from word representation to numbers.

## Building with CMake 
- create a build folder and navigate to it
```
mkdir buid <br/>
cd build
```
- build and compile
```
cmake ..  
cmake --build .  
```
-  you should have a file named libNumifier.a in the build folder

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
int number = parser::parseNumber(str,numifier::LANGUAGE::HUNGARIAN);  
int number = parser::parseNumber(str,numifier::LANGUAGE::ROMAN_NUMERALS);
```
## The algorithm
### Step 1 Format the input string
Remove the spaces,hyphens and all the "and" words from the string
for example the string "one thousand three hundred twenty-four" will become "onethousandthreehundredtwentyfour"  
(not yet implemented)
### Step 2 Segmentate the input string

Segmentate the string according to a a dictionary
Create an integer vector by slicing the string and translating the parts according to the dictionary

For example using the result from Step 1, the string "onethousandthreehundredtwentyfour" will become [1,1000,3,100,20,4]

Currently only English, Hungarian, and Roman Numerals are supported.  
### Step 3 Construct the number 
If you splice the result array from Step2 along the maximum value, put the maximum in the root node of a binary tree, and repeat the process recursively on the left and right side of the array, and you should have a binary tree like this:
![image](https://user-images.githubusercontent.com/57011394/182153137-c3874073-0efc-469c-8dfb-da40cdac5a84.png)  
After constructing the tree, with inorder traversal multiply the node with the left side, and add the right side, and the result should be the final result.
note that the library does the algorith on a std::vector, it does not construct the binary tree and traverse it.





 
    
  
