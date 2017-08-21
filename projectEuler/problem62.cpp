#include <iostream>
#include <time.h>
#include <sstream>
#include <string>
#include <map>
using namespace std;


//Implement a heap sort for improvement


struct data {
	int firstNumber;
	int count;
	data() : firstNumber(0), count(1) {}
	data(int number) : firstNumber(number), count(1) {}
};


string tostring(long long num) {
	ostringstream ss;
	ss << num;
	return ss.str();
}

void sort(string& num) {
	for (int i = 0; i < num.length() - 1; i++) {
		int k = i + 1;
		while (k > 0 && num[k] > num[k - 1]) {
			int temp = num[k];
			num[k] = num[k - 1];
			num[k - 1] = temp;
			k--;
		}
	}
}

long long cube(int num) {
	return (long long)num * num * num;
}

int main() {

clock_t time = clock();

//Store the permutations
map<string, data> perms;
int result = 0;
for (int i = 200; i < 10000; i++) {
	long long curr = cube(i);
	string number = tostring(curr);
	sort(number);
	if (perms.find(number) == perms.end()) {
		perms.insert(pair<string, data>(number, data(i)));	
	}
	else {
		perms[number].count++;
		if (perms[number].count == 5) {
			result = perms[number].firstNumber;
			break;
		}		
	}
}

cout << result << ": " << (long)result * result * result << endl;
cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;



}
