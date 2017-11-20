//Thomas Salemy
//Project Euler Solutions
//Problem 48: Self powers
//Question: Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.

#include <iostream>
#include <time.h>
using namespace std;


//Represent the first ten digits as an array, and
//do elementary addition where we carry over digits
//when they exceed ten in its digit column. 
//Reuse the same array by keeping track of size, 
//this increases effectiveness and efficiency
void sum(int result[10], int& size) {
	for (int i = 9; i >= 10 - size && i > 0; i--) {
		while (result[i] >= 10) {
			if (i == 0) {
				break;
			}
			if (i == 10 - size) {
				result[i - 1] = result[i] / 10;
				result[i] %= 10;
				size++;
			}
			else {
				result[i - 1] += result[i] / 10; 
				result[i] %= 10;
			}	
			i--;
		}
	}
    //When done, make sure the tength digit < 10
    //so that digits aren't recorded past that
	result[0] %= 10; 
}

//Calculatue the first ten digits for each
//number raised to itself by constantly
//re-evaluating the array and the
//digits through the sum method above
void power(int num, int result[10]) {	
	result[9] = num;
	int size = 1;
	sum(result, size);
	int pow = num;
	
	while (pow > 1) {
		for (int i = 9; i >= 10 - size; i--) {
			result[i] *= num;
		}
		sum(result, size);
		pow--;
	}
}

int main() {
    clock_t time = clock();

    int sumTotal[10] = {0 };
    int current[10] = {0};
    for (int i = 1; i <= 1000; i++) {
	    power(i, current);
	    for (int i = 0; i < 10; i++) {
		    sumTotal[i] += current[i];
	    }
    }

    //Using the same sum method with size 10 to
    //output the first 10 digits of the sum
    int size = 10;
    sum(sumTotal, size);


    cout << "Answer: ";
    for (int i = 0; i < 10; i++) {
	    cout << sumTotal[i];
    }
    cout << endl << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}
