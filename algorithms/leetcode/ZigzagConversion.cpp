#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string convert(string s, int rows) {
    if (rows >= s.length()) {
      return s;
    }
    else if (rows <= 1) {
      return s;
    }

    //Create grid
    vector<string> grid(rows, "");

    //Store length of string, to be compared
    //to a counter for getting specific chars
    int length = s.length();
    int counter = 0;
    //Initial grid position
    int row = 0;
    //Toggle to determine where to shift
    int shift = 0;

    while (counter < length) {
      //Set the appropriate row/col to a char
      grid[row].append(1, s[counter]);
      //Update the shifter
      if (row == 0) {
        shift = 1;
      }
      else if (row == rows - 1) {
        shift = -1;
      }
      row += shift;
      counter++;
    }

    //Create the new string
    string result = "";
    for (int i = 0; i < rows; i++) {
      if (grid[i].length() != 0) {
        result.append(grid[i]);
      }
    }
    return result;
  }
};
