#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
using namespace std;

bool isPalindrome(int& num) {
	ostringstream ss;
	ss << num;
	string temp = ss.str();
	for (int i = 0; i < temp.length() / 2; i++) {
		if ( temp[i] != temp[temp.length() - 1 - i] ){
			return false;
		}
	}
	return true;
}


bool binaryPalindrome(int num) {
	//Store binary in a temporary variable,
	//where digits are reversed. If palindrome,
	//this does not affect outcome.
	vector<int> temp;
	int number = num;
	while (num > 0) {
		if (num % 2 == 1) {
			num -= 1;
			temp.push_back(1);
		}
		else {
			temp.push_back(0);
		}
		num /= 2;
	}
	
	int bound = temp.size();
	for (int i = 0; i < bound / 2; i++) {
		if ( temp[i] != temp[bound - 1 - i] ) {
			return false;
		}
	}
	return true;
}

int main() {
	clock_t time = clock();

	int SUM = 0;
	int MAX = 1000000;
	for (int i = 1; i < MAX; i += 2) {
		if ( isPalindrome(i) ) {
			if ( binaryPalindrome(i) ) {
				SUM += i;
			}
		}
	}
	
	cout << "Answer: " << SUM << endl;
	cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
}
