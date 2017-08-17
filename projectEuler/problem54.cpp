#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


//Scoring:
//HighCard = 1
//OnePair = 2
//TwoPair = 4
//Three of a Kind = 8
//Straight = 16
//Flush = 31
//Full House = 61
//Four Of A Kind = 121
//Straight Flush = 241
//Royal Flush = 481


void sort(int hand[5][2]) {
	for (int i = 0; i < 4; i++) {
		int k = 0;
		int count = 0;
		for (int k = 0; k < 4 - i; k++) {
			if (hand[k][0] < hand[k + 1][0]) {
				int temp1 = hand[k][0];
				int temp2 = hand[k][1];
				hand[k][0] = hand[k + 1][0];
				hand[k][1] = hand[k + 1][1];
				hand[k + 1][0] = temp1;
				hand[k + 1][1] = temp2;
				count++;
			}
		}
		if (count == 0) {
			break;
		}
	}
}

bool straight(int hand[5][2]) {
	for (int i = 0; i < 4; i++) {
		if (hand[i][0] - 1 != hand[i + 1][0]) {
			return false;
		}
	}
	return true;
}
bool compareMax(int hand[5][2], int hand2[5][2]) {
	for (int i = 0; i < 5; i++) {
		if (hand[i][0] > hand2[i][0]) {
			return true;
		}
		else if (hand[i][0] < hand2[i][0]) {
			return false;
		}
	}
	//This wont get reached in our case, but needed to compile
	return false;
}



bool flush(int hand[5][2]) {
	for (int i = 0; i < 4; i++) {
		if (hand[i][1] != hand[i + 1][1]) {
			return false;
		}
	}
	return true;
}


bool scores(int hand[5][2], int hand2[5][2]) {
	
	//Sort hands
	sort(hand);
	sort(hand2);	

	//Initiate Scores
	int playerAScore = 0;
	int playerBScore = 0;	

	//Get info on Pairs
	int twoPairA[2] = { };
	int threePairA = 0;
	int fourPairA = 0;

	int twoPairB[2] = { };
	int threePairB = 0;
	int fourPairB = 0;
	
	for (int i = 0; i < 4; i++) {
		int currCount = 0;
		while (i < 4 && hand[i][0] == hand[i + 1][0]) {
			currCount++;
			i++;
		}
		if (currCount == 1) {
			if (twoPairA[0] == 0) {
				twoPairA[0] = hand[i][0];
			}
			else {
				twoPairA[1] = hand[i][0];
			}
			playerAScore += 2;	
		}
		else if (currCount == 2) {
			threePairA = hand[i][0];
			if (twoPairA[0] != 0) {
				playerAScore += 59;
			}
			else {
				playerAScore += 8;
			}
		}
		else if (currCount == 3) {
			fourPairA = hand[i][0];
			playerAScore += 241;
			break;
		}
	}
	
	for (int i = 0; i < 4; i++) {
		int currCount = 0;
		while (i < 4 && hand2[i][0] == hand2[i + 1][0]) {
			currCount++;
			i++;
		}
		if (currCount == 1) {
			if (twoPairB[0] == 0) {
				twoPairB[0] = hand2[i][0];
			}
			else {
				twoPairB[1] = hand2[i][0];
			}
			playerBScore += 2;
		}
		else if (currCount == 2) {
			threePairB = hand2[i][0];
			if (twoPairB[0] != 0) {
				playerBScore += 59;
			}
			else {
				playerBScore += 8;
			}
		}
		else if (currCount == 3) {
			fourPairB = hand2[i][0];
			playerBScore += 241;
			break;
		}
	}

	//Get info on flushes
	bool flushA = flush(hand);
	if (flushA) {
		playerAScore += 31;
	}
	bool flushB = flush(hand2);
	if (flushB) {
		playerBScore += 31;
	}

	if (playerAScore > 0 || playerBScore > 0) {
		if (playerAScore > playerBScore) {
			return true;
		}
		else if (playerAScore < playerBScore) {
			return false;
		}
		else if (playerAScore != 31) {
			
			//If equal... look for highest cards
			//Four Pair (no four pair can be equal)
			if (fourPairA != 0) {
				if (fourPairA > fourPairB) {
					return true;
				}
				return false;
			}
			//Three pair / full house /  with flush
			if (threePairA != 0) {
				if (threePairA > threePairB) {
					return true;
				}
				return false;
			}
			//Two pairs / with flush
			if (twoPairA[1] != 0) {
				int Amax = twoPairA[1];
				if (twoPairA[0] > twoPairA[1]) {
					Amax = twoPairA[0];
				}
				int Bmax = twoPairB[1];
				if (twoPairB[0] > twoPairB[1]) {
					Bmax = twoPairB[0];
				}	
				
				if (Amax > Bmax) {
					return true;
				}
				else if (Bmax > Amax) {
					return false;
				}
				return compareMax(hand, hand2);
			}
			//Single pair / single pair with flush
			if (twoPairA[0] != 0) {
				if (twoPairA[0] > twoPairB[0]) {
					return true;
				}
				if (twoPairA[0] < twoPairB[0]) {
					return false;
				}	
				return compareMax(hand, hand2);
			}
		}
	}
	
	//if no pairs, then theres the chance of a straight
	bool straightA = straight(hand);
	if (straightA) {
		if (flushA) {
			if (hand[0][0] == 14) {
				return true;
			}
			else {
				playerAScore += 241;
			}
		}
		else {
			playerAScore += 16;
		}
	}
	bool straightB = straight(hand2);
	if (straightB) {
		if (flushB) {
			if (hand2[0][0] == 14) {
				return true;
			}
			else {
				playerAScore += 241;
			}
		}
		else {
			playerBScore += 16;
		}
	}

	if (playerAScore > playerBScore) {
		return true;
	}
	else if (playerAScore < playerBScore) {
		return false;
	}
	//if scores are all equal, that means both have straight or straight flush
	//so can only check highest card or nothing
	return compareMax(hand, hand2);
	
}


int main() {

clock_t time = clock();

ifstream file("problem54.txt");
if ( !file.is_open() ) {
	cout << "Could not open file" << endl;
	return -1;
}


int player1wins = 0;
int player1Hand[5][2] = { };
int player2Hand[5][2] = { };
for (int i = 0; i < 1000; i++) {
	char number;
	char suit;	
	for (int k = 0; k < 10; k++) {
		file >> number;
		file >> suit;
		if (number > '9') {
			if (number == 'J') {
				number = 11 + '0';
			}
			else if (number == 'Q') {
				number = 12 + '0';
			}
			else if (number == 'K') {
				number = 13 + '0';
			}
			else {
				number = 14 + '0';
			}
		}
		if (k < 5) {
			player1Hand[k][0] = number - '0';
			player1Hand[k][1] = suit;
		}
		else {
			player2Hand[k - 5][0] = number - '0';
			player2Hand[k - 5][1] = suit;
		}
	}
	
	if (scores(player1Hand, player2Hand)) {
		player1wins++;
	}
}

cout << player1wins << endl;
cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}
