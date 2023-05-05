#include <iostream>
#include <map>
#include <string>
#include <vector>
/*

We are hiding some word in a 2D grids of letters. words
may start anywhere in the grid, and consecutive letters can be only:

- immediately below
OR
- immediately to the right

of the previous letter.

Given a grid and a word, write a function that returns the location of the
letters of the word in the grid as a list of coordinates.

- If there are multiple matches, return any one.
- If there are no matches, return an empty vector.

Example Input and outputs:

Suppose:

grid1 = [
    ['c', 'c', 't', 'n', 'a', 'x'],
    ['c', 'c', 'a', 't', 'n', 't'],
    ['a', 'c', 'n', 'n', 't', 't'],
    ['t', 'n', 'i', 'i', 'p', 'p'],
    ['a', 'o', 'o', 'o', 'a', 'a'],
    ['s', 'a', 'a', 'a', 'o', 'o'],
    ['k', 'a', 'i', 'o', 'k', 'i'],
]

And suppose:

word1 = "catnip"
word2 = "cccc"
word3 = "s"
word4 = "ant"
word5 = "aoi"
word6 = "BATMAN"
word7 = ""

Your program should generate the following outputs:
FindWordLocation(grid1, "catnip") =>
  [ (1, 1), (1, 2), (1, 3), (2, 3), (3, 3), (3, 4) ]

FindWordLocation(grid1, "cccc") =>
    [(0, 0), (1, 0), (1, 1), (2, 1)]

    OR

    [(0, 0), (0, 1), (1, 1), (2, 1)]

FindWordLocation(grid1, "s") => [(5, 0)]

FindWordLocation(grid1, "ant") =>
    [(0, 4), (1, 4), (2, 4)]

    OR

    [(0, 4), (1, 4), (1, 5)]

FindWordLocation(grid1, "aoi") => [(4, 5), (5, 5), (6, 5)]

FindWordLocation(grid1, "BATMAN") => []

FindWordLocation(grid1, "") => []


Complexity analysis variables:

r = number of rows
c = number of columns
w = length of the word
*/

std::vector<std::pair<int, int>> FindWordLocation(
    std::vector<std::vector<char>> grid, std::string word);