//
//  problem9.cpp
//  
//
//  Created by Thomas Salemy on 6/13/17.
//
//Needs to be optimized, have not gotten to the number theory  yet and have not found better solution
//but to use the facts: a < b < c. a < 1000 /3,  b < 1000 / 2, c = whatever the target is (1000 in this case) - a - b
//
//Will save optimization for future date

#include <iostream>
#include "time.h"

using namespace std;

//Needs to be optimized
bool isPythagorean(int a, int b, int c) {
    return a * a + b * b == c * c;
};

//We will assume that a, or i in this case, is less than 333 since it needs to be less than 1 / 3 about.
//We will assume tha b, or j in this case, is less than 500 since it needs to be less than 1/2 about
int main() {
    int i;
    int j;
    int k;
    bool checker = false;
    clock_t time = clock();
    for (i = 3; i < 340; i++) {
      for (j = i + 1; j < 500; j++) {
        k = 1000 - i - j;
        if (isPythagorean(i, j, k)) {
          if (i + j + k == 1000) {
            checker = true;
            break;
          }
        }
      }
      if (checker == true) {
          break;
      }
    }
        
    
  cout << "Answer: " << i << "^2 + " << j << "^2 = " << k << "^2, " << i * j * k << endl;
  cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
  return 0;
};
