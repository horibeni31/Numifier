enable_testing()
add_executable(englishTest test_english.cpp)
target_link_libraries(englishTest numifier)

# define tests
add_test(
  NAME englishTest
  COMMAND $<TARGET_FILE:englishTest>
  )
