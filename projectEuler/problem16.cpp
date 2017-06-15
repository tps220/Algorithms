#include <iostream>
#include <vector>
#include <time.h>
using namespace std;


int main() {

clock_t time = clock();
vector<int> integerMap;

//Estimate of how large the number will be
integerMap.reserve(350);

//Initialize first number to 1 :)
integerMap.push_back(1);

for (int i = 1; i <= 1000; i++) {
	for (int j = 0; j < integerMap.size(); j++) {
		integerMap[j] *= 2;
		while (integerMap[j] >= 10) {
			if (j < integerMap.size() - 1) {
				integerMap[j + 1] = integerMap[j + 1] * 2 + 1;
			}
			else {
				integerMap.push_back(1);
			}
			integerMap[j] -= 10;
			j++;
		}
	}
};


//Calculate Sum
int sum = 0;
for (int i = 0; i < integerMap.size(); i++) {
	sum += integerMap[i];
}
cout << "Answer: " << sum << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

};
	
