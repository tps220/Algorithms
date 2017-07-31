#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <map>
using namespace std;


int frequencyAnalysis(vector<int>& chars, int& start) {
	map<int, int> freq;
	int MAX = 0;
	int frequentNum = 0;
	for (int i = start; i < chars.size(); i += 3) {
		if (freq.find(chars[i]) == freq.end()) {
			freq.insert(pair<int, int>(chars[i], 1));
		}
		else {
			freq[chars[i]]++;
			if (freq[chars[i]] > MAX) {
				MAX = freq[chars[i]];
				frequentNum = chars[i];
			}
		}
	}
	return frequentNum;
}

int main() {

clock_t time = clock();

long SUM = 0;
ifstream file("problem59.txt");
if (file.is_open()) {
	vector<int> chars;
	char ch;
	int counter = 0;
	int index = 0;
	while (file >> ch) {
		if (ch == ',') {
			if (counter == 1) {
				chars[index] /= 10;
			}
			index++;
			counter = 0;
		}
		else if (counter == 0) {	
			chars.push_back( (ch - 48) * 10);
			counter++;
		}
		else {
			chars[index] += ch - 48;
			counter++;
		}
	}
	int* key = new int[3];
	for (int i = 0; i < 3; i++) {
		int curr = frequencyAnalysis(chars, i);
		key[i] = curr ^ ' ';
	}
	for (int i = 0; i < chars.size(); i++) {
		chars[i] = chars[i] ^ key[i % 3];
		SUM += chars[i];
	}
	delete [] key;
} else {
	cout << "File could not open" << endl;
	return 1;
}
cout <<  SUM << endl;
cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
return 0;
}
