//Thomas Salemy
//Project Euler Solutions
//Problem 38: Pandigital Multiples
//Question: What is the largest 1 to 9 pandigital 9-digit number that 
//can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?


#include <iostream>
#include <time.h>
#include <sstream>
#include <string>
using namespace std;

int pandigital(string number) {
	for (int i = 0; i < number.length() - 1; i++) {
		for (int k = i + 1; k < number.length(); k++) {
			if (number[i] == number[k] || number[k] == '0') {
				return 0;
			}
		}
	}
	if (number.length() > 9) {
		return 1;
	}
	if (number.length() < 9) {
		return 2;
	}
	return -1;
}


int main() {
    clock_t time = clock();
    string result = "";
    for (int i = 9999; i > 200; i--) {
	    int outcome = 2;
	    string number;
	    int count = 1;	
	    ostringstream ss;
	    while (outcome > 1) {
            ss << i * count;
		    number = ss.str();
		    outcome = pandigital(number);
		    count++;
	    }
	    if (outcome == -1) {
		    result = number;
		    break;
	    }
    }
    cout << "Answer: " << result << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}
