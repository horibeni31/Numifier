mkdir build
cmake -S. -Bbuild
cmake --build build
ctest --test-dir build/tests