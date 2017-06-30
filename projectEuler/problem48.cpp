#include <iostream>
#include <time.h>
using namespace std;


//Represent the first ten digits as an array, and
//do elementary addition where we carry over digits
//when they exceed ten in its column. Reuse the same array
//by keeping track of size, this increases effectiveness
//and efficiency
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
	result[0] %= 10; //The tength digit must be < 10 as
			//we dont want to record digits past that
}

//Calculatue the first ten digits for each
//number raised to itself by constantly
//re-evaluating the array and the
//digits through the sum method
//everytime its multiplied by the base
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

//Use the power method for numbers 1 - 1000,
//adding the result to our overall sum
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


//Report answer
cout << "Answer: ";
for (int i = 0; i < 10; i++) {
	cout << sumTotal[i];
}
cout << endl << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;




}
