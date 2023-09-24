
project(numifier VERSION 1.0)
add_library(numifier src/numifier.cpp include/numifier.h include/languages.h)
target_include_directories(numifier PUBLIC "include")
