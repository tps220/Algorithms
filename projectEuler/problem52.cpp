#include <iostream>
#include <time.h>
using namespace std;


bool isPermutation(long num1, long num2) {
	int number1[10] = { };
	int number2[10] = { };
	while (num2 > 0) {
		number1[num1 % 10]++;
		number2[num2 % 10]++;
		num1 /= 10;
		num2 /= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (number1[i] != number2[i]) {
			return false;
		}
	}
	return true;
}

int size(long num) {
	if (num < 10) {
		return 1;
	}
	return 10 * size(num / 10);

}

int main() {

clock_t time = clock();

long num = 1333;
for (;;) {
	int length = size(num);
	if (num / length != 1) {
		num += length * 8;
	}
	int count = 0;
	for (int i = 2; i < 7; i++) {
		if (!isPermutation(num, num * i)) {
			break;
		}
		count++;
	}
	if (count == 5) {
		break;
	}
	num++;
}



cout << "Answer: " << num << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}
