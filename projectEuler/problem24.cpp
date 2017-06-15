//Lexicographic Permutations Baby
//

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;


int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 1;
	}
	while (n != 1) {
		return n * factorial(n - 1);
	}
}


int main() {

clock_t time = clock();

//Initialize map of numbers that can be dynamically removed
vector<int> numberMap;
for (int i = 0; i < 10; i++) {
	numberMap.push_back(i);
}

//Original Lexicographic Placement
int LEXO = 1000000;

//Algorithm

int scale = 9;
int subtractor;
int count;
while (scale >= 0) {
	subtractor = factorial(scale);
	count = 0;
	while (LEXO > subtractor) {
		LEXO -= subtractor;
		count++;
	}
	numberMap.push_back(numberMap[count]);
	numberMap.erase(numberMap.begin() + count);
	scale--;
}


//Print Final Answer + Time
cout << "Answer: ";
for (int i = 0; i < numberMap.size(); i++) {
	cout << numberMap[i];
}
cout << endl << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
};
