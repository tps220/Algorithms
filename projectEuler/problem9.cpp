//Thomas Salemy
//Project Euler Solutions
//Problem 9: Special Pythagorean triplet
//Question: There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product a * b * c

#include <iostream>
#include <time.h>
using namespace std;


//**Needs to be optimized
bool isPythagorean(int &a, int &b, int &c) {
    return a * a + b * b == c * c;
};

int main() {
    int i, j, k;
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
