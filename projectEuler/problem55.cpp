#include <iostream>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;


bool isPalindrome(unsigned long long& number) {
	ostringstream ss;
	ss << number;
	string temp = ss.str();
	int length = temp.length();
	for (int i = 0; i < length / 2; i++) {
		if ( temp[i] != temp[length - i - 1] ) {
			return false;
		}
	}
	return true;
}
void reverseNum(unsigned long long &number) {
	unsigned long long result = 0;
	while (number > 0) {
		result *= 10;
		result += number % 10;
		number /= 10;
	}
	number = result;
}



int main() {

clock_t time = clock();

int lychrelCount = 0;
int start = 1;
unsigned long long result;
unsigned long long temp;
while (start <= 10000) {
	result = start;
	temp = start;
	reverseNum(temp);
	result += temp;
	int currCount = 1;
	while (currCount < 50) {
		if ( isPalindrome(result) ) {
			break;
		}
		temp = result;
		reverseNum(temp);
		result += temp;
		currCount++;
	}
	if (currCount == 50) {
		lychrelCount++;
	}
	start++;
}

cout << "Answer: " << lychrelCount << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;



}
