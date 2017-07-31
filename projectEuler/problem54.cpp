#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;



void highCard(int hand[10][2], int& playerA, int& playerB) {
	if (hand[0][0] > hand[5][0]) {
		playerA++;
	}
	else {
		playerB++;
	}
}

void onePair(int hand[10][2], int& playerA, int& playerB) {



}



int main() {

clock_t time = clock();

ifstream file("problem54.txt");
if ( !file.is_open() ) {
	cout << "Could not open file" << endl;
	return -1;
}


int player1wins = 0;
int hands[10][2] = { };
for (int i = 0; i < 1000; i++) {
	char number;
	char suit;	
	for (int k = 0; k < 5; k++) {
		file >> number;
		file >> suit;
		if (number > '9') {
			if (number == 'J') {
				number = 11;
			}
			else if (number == 'Q') {
				number = 12;
			}
			else if (number == 'K') {
				number = 13;
			}
			else {
				number = 14;
			}
			hands[k][0] = number;	
		}
		else {
			hands[k][0] = number - '0';
		}
		hands[k][1] = suit;
	}
	
	for (int i = 0; i < 4; i++) {
		int k = i;
		while (k < 4 && hands[k] < hands[k + 1]) {
			int[] temp = hands[k];
			hands[k] = hands[k + 1];
			hands[k + 1] = temp;	
		}
	}
	
	int playerA = 0;
	int playerB = 0;

}



}
