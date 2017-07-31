#include <iostream>
#include <time.h>
#include <vector>
using namespace std;


int findSum(int& a, int b) {
	vector<int> digits;
	digits.push_back(a);
	while (b > 1) {
		for (int i = 0; i < digits.size(); i++) {
			digits[i] *= a;
		}
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] > 9) {
				if (i == digits.size() - 1) {
					digits.push_back(digits[i] / 10);			
					digits[i] %= 10;
				}
				else {
					digits[i + 1] += digits[i] / 10;
					digits[i] %= 10;
				}
			}
		}
		b--;
	}
	int SUM = 0;
	for (int i = digits.size() - 1; i >= 0; i--) {
		SUM += digits[i];
	}
	return SUM;
}

int main() {


clock_t time = clock();

int MAX = 1;
for (int a = 11; a < 100; a++) {
	for (int b = 11; b < 101; b++) {
		int sum = findSum(a, b);	
		if (sum > MAX) {
			MAX = sum;
		}
	}
}

cout << "Answer: " << MAX << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}
