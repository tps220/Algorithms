#include <iostream>
#include <time.h>

using namespace std;

int main() {
clock_t time = clock();

int bound = 10000 / 2 + 1;
int factorSumMap[10000] = {0};


for (int i = 1; i < bound; i++) {
	for (int j = i * 2; j < 10000; j+= i) {
		factorSumMap[j] += i;
	}
}

int sum = 0;
for (int i = 10; i < 10000; i++) {
	int temp = factorSumMap[i];
	if (temp < 10000 && temp != i) {
		if (i == factorSumMap[temp]) {
			sum += i;
		}
	}
}
cout << "Answer: " << sum << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}
