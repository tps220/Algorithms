#include <iostream>
#include "time.h"
#include <sstream>
#include <set>
using namespace std;



//Check if its pandigital
bool pandigital(int m1, int m2, int num) {
	ostringstream ss;
	ss << m1;
	ss << m2;
	ss << num;
	string numberStream = ss.str();
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (numberStream[j] == '0') {
				return false;
			}
			if (numberStream[i] == numberStream[j]) {
				return false;
			}
		}
	}
	
	return true;
	
	//to check and make sure they are all valid:
	//cout << numberStream << endl;

	//Another way to do it without using strings, but trickily with sets:
	//set<int> map;
	//map.insert(m1 / 10);
	//map.insert(m1 % 10);
	//map.insert(m2 /100);
	//map.insert((m2 / 10) % 10);
	//map.insert(m2 % 10);
	//if (map.size() < 5) {
	//	return false;
	//}
	//map.insert(num / 1000);
	//map.insert( (num / 100) % 10);
	//map.insert( (num / 10) % 10);
	//map.insert( num % 10);
	
	//Taking advantage of a set, if 0 is placed inside the set,
	//that means no duplicates are present and therefore the
	//number 0 was not in the set, which is what we want
	//since the number is supposed to be 
	//1 to 9 pandigital.
	//
	//We would do:
	//map.insert(0) and return map.size() == 9;
	//
	//Another way to implement this would to be simply
	//adding another clause to the return statement,
	//and say map.size() == 9 && map.find(0) == map.end();
	//By taking advantage of c++, only the first part of the
	//map statement will execute before the second if its
	//proven false. Therefore, we will decrease the amount of times
	//we need to check for 0 for a few special cases, increasing
	//efficiency
	//
	//return map.size() == 9 && map.find(0) == map.end();
}



int main() {
clock_t time = clock();


//Make sure there are no duplicates
set<int> duplicates;


int SUM = 0;
for (int i = 1; i < 100; i++) {
	int j;
	if (i > 9) {
		j = 100;
	}
	else {
		j = 1000;
	}
	while ( i * j < 9999) {
		if (pandigital(i, j, i * j)) {
			if (duplicates.find(i * j) == duplicates.end()) {	
				SUM += i * j;
				cout << i << " * " << j << " = " << i * j << endl;
				duplicates.insert(i * j);
			}
			
		}
		j++;
	}
}
cout << "Answer: " << SUM << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;



}
