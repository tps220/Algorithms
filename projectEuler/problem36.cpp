//Thomas Salemy
//Project Euler Solutions
//Problem 36: Double Base Palindorme 
//Question: Find the sum of all numbers below one million
//which are palindromic in base 10 and base 2

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
using namespace std;

bool isPalindrome(int &num) {
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
    int right = 0;
    int left = sizeof(int) * 8 - 1;
    while (left >= 0 && ((num >> left) & 1) == 0) {
        left--;
    }
    while (left > right) {  
        if ( ((num >> right) & 1) != ((num >> left) & 1)) {
            return false;
        }
        right++;
        left--;
	}
	return true;
}

int main() {
	clock_t time = clock();

	int SUM = 0;
	const unsigned int MAX = 1000000;
	for (int i = 1; i < MAX; i += 2) {
		if (isPalindrome(i) ) {
			if (binaryPalindrome(i)) {
				SUM += i;
			}
		}
	}
	
	cout << "Answer: " << SUM << endl;
	cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
}
