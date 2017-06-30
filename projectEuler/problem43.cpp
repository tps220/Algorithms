#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;


bool pandigital(long long& num) {
	ostringstream ss;
	ss << num;
	string digits = ss.str();

	//IsPandigital?
	for (int i = 0; i < 9; i++) {
		for (int k = i + 1; k < 10; k++) {
			if (digits[i] == digits[k]) {
				return false;
			}
		}
	}
	return true;
}





//Our main goal with this long, complicated loop structure
//is to create all the numbers that match the rules. By
//doing this, we only have to check if they're pandigital
//and add them to the total sum. 

int main() {

clock_t time = clock();
long long result = 0;
long long number;


for (int a = 1024; a < 9876; a += 2) {
	
	//Find the 5th digit
	int k = (a  % 100) * 10;
	while (k % 3 != 0) {
		k++;
	}
	int b = k % 10;
	while (b < 10) {
		//Find the sixth digit using
		//what the last three are. Continue
		//to update k as we update the fifth digit
		int j = (k % 100) * 10;
		while (j % 5 != 0) {
			j++;
		}
		k += 3;

		int c = j % 10;
		while (c < 10) {
			
			//Find the seventh digit,
			//and continue to update j
			//as we update the sixth digit
			int l = (j % 100) * 10;
			while (l % 7 != 0) {
				l++;
			}
			j += 5;

			int d = l % 10;
			while (d < 10) {
				//Eigth
				int m = (l % 100) * 10;
				while (m % 11 != 0) {
					m++;
				}
				if ( (m / 10) % 10 == d) {
				
					int e = m % 10;		
		
					//Ninth
					int n = (m % 100) * 10;
					while (n % 13 != 0) {
						n++;
					}
					if ( (n / 10) % 10  == e) {

						int f = n % 10;
				
						//Tenth
						int o = (n % 100) * 10;
						while (o % 17 != 0) {
							o++;
						}
						if ( (o / 10) % 10 == f) {
						
						int g = o % 10;
				
						//Compute what number would be
						number = (long)a * 1000000 + (long)b * 100000 + (long)c * 10000 + (long)d * 1000 + (long)e * 100 + (long)f * 10 + g;

						//If number is pandigital, add to sum
						if ( pandigital(number) ) {
							result += number;
							cout << number << endl;
						}
						}
					}
				}
				//update l as we update the seventh digit
				l += 7;
				d += 7;	
			}	
			c+= 5;
		}
		b += 3;
	}
}
			
	

cout << "Answer: " << result << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}

