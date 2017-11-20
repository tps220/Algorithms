//Thomas Salemy
//Project Euler Solutions
//Problem 40: Champernowne's constant
//If dn represents the nth digit of the fractional part, find the value of the following expression.
//d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;


int main() {

clock_t time = clock();

int multiplier = 1;
int target = 1;
int currentNum = 1;
int count = 1;

while (target <= 1000000) {
    if (count >= target ) {
        multiplier *= (currentNum / (int)pow(10, count - target)) % 10;
        target *= 10;
    }
    currentNum++;
    if (currentNum > 99999) {
        count += 5;
    }
    else if (currentNum > 9999) {
        count += 4;
    }
    else if (currentNum > 999) {
        count += 3;
    }
    else if (currentNum > 99) {
        count += 2;
    }
    else if (currentNum > 9) {
        count++;
    }
    count++;
}
    cout << "Answer: " << multiplier << endl;
    cout << "Time: " << (clock() - time) / (double)CLOCKS_PER_SEC << endl;
}
