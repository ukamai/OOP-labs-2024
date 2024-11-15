#include <gtest/gtest.h>


TEST(test_01, basic_test_set) {
  // arrange 
  std::string str = absbdfbaaa;
  int result = countVowels(str);
  ASSERT_TRUE(result == 0);
}
