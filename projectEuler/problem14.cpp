#include <iostream>
#include <time.h>
using namespace std;


int main() {


clock_t time = clock();
int collatzMap[1000000] = {0};
collatzMap[1] = 1;
int maxChain = 0;
int maxNumber = 0;

unsigned long long number;
int count;
for (int i = 2; i < 1000000; i++) {
	number = i;
	count = 0;
	while (number != 1) {
		if (number < 1000000) {
			if (collatzMap[number] != 0) {
				break;
			}
		}
		if (number % 2 == 0) {
			number /= 2;
		}
		else {
			number = number * 3 + 1;
		}
		count++;
	}
	collatzMap[i] = collatzMap[number] + count;
	if (collatzMap[i] > maxChain) {
		maxChain = collatzMap[i];
		maxNumber = i;
	}
}
cout << "Number: " << maxNumber << ", chain length: " << maxChain << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
};

