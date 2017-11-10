//Thomas Salemy
//Project Euler Solutions
//Problem 6: Sum square difference
//Question: Find the difference between the sum of the squares
//of the first one hundred natural numbers and the square of the sum

#include <iostream>
#include <time.h>
using namespace std;


//This program will take advantage of counting principles
//(1) the sum of numbers from 1 to n is n * (n + 1) / 2
//(2) the sum of a number squared from 1 to n is n * (n + 1) * (2n + 1) / 6

int main() {
    clock_t time = clock();
    long sum = 100 * (100 + 1) / 2;
    long square = 100 * (100 + 1) * (200 + 1) / 6;

    cout << "Answer: " <<  sum * sum - square << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 1;
};




