//Project Euler Solutions
//Problem 1: Multiples of 3 and 5
//Thomas Salemy

#include <iostream>
using namespace std;


//The sum function will take advantage of distribution and
//that the sum of numbers from 1 to n is p * (p + 1) / 2 = (p^2 + p) / 2

//MAX acts as the bound, multiple is self-explanatory in the context
//of the problem
int sumFunction(int multiple, int MAX) {
	int n = MAX / multiple;
	return  n * (n + 1) / 2  * multiple;
};

int main() {
int sum = sumFunction(3, 999) + sumFunction(5, 999) - sumFunction(15, 999);
cout << sum;

};
