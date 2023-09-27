mkdir build
cmake -S. -Bbuild
cmake --build build
ctest --output-on-failure --test-dir build/tests 