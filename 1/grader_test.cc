#include <iostream>
#include <string>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAreArray;

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
std::vector<std::vector<char>> grid1 = {
    {'c', 'c', 't', 'n', 'a', 'x'},  //
    {'c', 'c', 'a', 't', 'n', 't'},  //
    {'a', 'c', 'n', 'n', 't', 't'},  //
    {'t', 'n', 'i', 'i', 'p', 'p'},  //
    {'a', 'o', 'o', 'o', 'a', 'a'},  //
    {'s', 'a', 'a', 'a', 'o', 'o'},  //
    {'k', 'a', 'i', 'o', 'k', 'i'},
};

bool CheckWord(std::vector<std::pair<int, int>> actual, std::string word) {
  if (actual.size() != word.size()) return false;
  for (size_t i = 0; i < word.size(); ++i) {
    if (grid1[actual[i].first][actual[i].second] != word[i]) {
      return false;
    }
  }
  return true;
}

bool VerifyValidation(std::vector<std::pair<int, int>> actual) {
  auto b_right = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first == b.first && a.second == b.second - 1;
  };

  auto b_below = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first == b.first - 1 && a.second == b.second;
  };

  for (size_t i = 1; i < actual.size(); ++i) {
    if (! (b_right(actual[i - 1], actual[i]) || b_below(actual[i - 1], actual[i]))) {
      return false;
    }
  }
  return true;
}

TEST(FindWordLocation, catnip) {
  std::string word = "catnip";
  auto actual = FindWordLocation(grid1, word);
  EXPECT_TRUE(VerifyValidation(actual) && CheckWord(actual, word));
}

TEST(FindWordLocation, cccc) {
  std::string word = "cccc";
  auto actual = FindWordLocation(grid1, word);
  EXPECT_TRUE(VerifyValidation(actual) && CheckWord(actual, word));
}

TEST(FindWordLocation, s) {
  std::string word = "s";
  auto actual = FindWordLocation(grid1, word);
  EXPECT_TRUE(VerifyValidation(actual) && CheckWord(actual, word));
}

TEST(FindWordLocation, ant) {
  std::string word = "ant";
  auto actual = FindWordLocation(grid1, word);
  EXPECT_TRUE(VerifyValidation(actual) && CheckWord(actual, word));
}

TEST(FindWordLocation, aoi) {
  std::string word = "aoi";
  auto actual = FindWordLocation(grid1, word);
  EXPECT_TRUE(VerifyValidation(actual) && CheckWord(actual, word));
}

TEST(FindWordLocation, aaoo) {
  std::string word = "aaoo";
  auto actual = FindWordLocation(grid1, word);
  EXPECT_TRUE(VerifyValidation(actual) && CheckWord(actual, word));
}

TEST(FindWordLocation, batman) {
  auto actual = FindWordLocation(grid1, "batman");
  std::vector<std::pair<int, int>> expected = {};
  EXPECT_EQ(actual, expected);
}

TEST(FindWordLocation, empty) {
  auto actual = FindWordLocation(grid1, "");
  std::vector<std::pair<int, int>> expected = {};
  EXPECT_EQ(actual, expected);
}
