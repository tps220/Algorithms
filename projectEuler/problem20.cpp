#include <iostream>
#include <time.h>
#include <vector>
using namespace std;


int main() {
clock_t time = clock();


vector<int> integerMap;
//Initialize first value, or 1!
integerMap.push_back(1);

for (int i = 2; i <= 100; i++) {
	for (int j = 0; j < integerMap.size(); j++) {
		integerMap[j] *= i;
		while (integerMap[j] >= 10) {
			if (j < integerMap.size() - 1) {
				integerMap[j + 1] *= i;
				integerMap[j + 1] += integerMap[j] / 10;
				integerMap[j] %= 10;
			}
			else {
				integerMap.push_back(integerMap[j] / 10);
				integerMap[j] %= 10;
			}
			j++;
		}
	}
}

int sum = 0;
for (int i = 0; i < integerMap.size(); i++) {
	sum += integerMap[i];
}

cout << "Answer: " <<  sum << endl;
cout << "Time: " <<  (clock() - time) / (double)CLOCKS_PER_SEC << endl;

};
