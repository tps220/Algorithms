#include <iostream>
#include <time.h>
#include <vector>
using namespace std;



int main() {

//Start the clock
clock_t time = clock();


//Store decimals dynamically
vector<int> patternMap;

//If number divides evenly, all its squares divide evenly
bool numbersSquareMap[1000] = {false};

//Initialize Max Outcomes
int maxSequence = 0;
int maxSequenceNumber = 0;

//Declare loop variables
int number;
int patternSize;

//Loop to one thousand
for (number = 2; number < 1000; number++) {
	

	//Pattern size always starts at 0
	patternSize = 0;

	//Start Algorithm
	if (!numbersSquareMap[number]) {

		int start = 10;
		bool patternNotMet = true;

	
		while (patternNotMet) {
			
			int count = 0; //how many times number divides into
			int decimalPlacement = -1; //how far over to move
			while (start < number) {
				start *= 10;
				decimalPlacement++;
				if (decimalPlacement > 0) {
					patternMap.push_back(start);
				}
			}
			while (start >= number) {
				start -= number;
			}

			//check for pattern
			if (start == 0) {
				for (int i = number * number; i < 1000; i *= number) {
					numbersSquareMap[i] = true;	
				}
				patternNotMet = false;	
			}
			else {
				for (int i = 0; i < patternMap.size(); i++) {
					if (start == patternMap[i]) {
						patternSize =  patternMap.size() - i;
						patternNotMet = false;
						break;
					}
				}
			}
		patternMap.push_back(start);	
		
		}
		if (patternSize > maxSequence) {
			maxSequence = patternSize;
			maxSequenceNumber = number;
		}
		patternMap.clear();
	}
}


cout << "Answer: " << maxSequenceNumber << ", " << maxSequence << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


};
