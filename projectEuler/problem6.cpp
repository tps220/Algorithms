//Project Euler Solutions
//Problem 6: Sum square difference
//Thomas Salemy

#include <iostream>
#include <ctime>
using namespace std;


//This program will take advantage of basic math knowledge:
//(1) the sum of numbers from 1 to n is n * (n + 1) / 2
//(2) the sum of a number squared from 1 to n is n * (n + 1) * (2n + 1) / 6
//From that, it can easily calculate the final answer in O(1) time

int main() {
clock_t time = clock();
long sum = 100 * (100 + 1) / 2;
long square = 100 * (100 + 1) * (200 + 1) / 6;

cout << "Answer: " <<  sum * sum - square << endl;

time = clock() - time;
cout << "Seconds: " << time / (double) CLOCKS_PER_SEC;
return 1;
};




