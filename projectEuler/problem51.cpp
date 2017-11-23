//Thomas Salemy
//Project Euler Solutions
//Problem 51

#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;


//If prime, increment current iterator for number of primes
void isPrime(bool *sieve, int& primes, vector<char>& numberString, int& result) {	
    //Calculate Number
    int number = 0;
	for (int digit = 0; digit < numberString.size(); digit++) {
		number += (numberString[digit] - '0') * pow(10, numberString.size() - digit - 1);
	}
    //Check if prime
	if (!sieve[number]) {
		primes++;
		if (primes == 1) {
			result = number;
		}
	}
    return;
}


int followRules(int &num, bool *sieve) {
	//Create a string representation of the number
	ostringstream toString;
	toString << num;
	string temp = toString.str();
	
	//Create a dynamic array of chars from string representation
	int length = temp.length();
	vector<char> numberString;		
	for (int i = 0; i < length; i++) {
		numberString.push_back(temp[i]);
	}

	//Based on length, try all possiblities
	for (int count = 0; count < length; count++) {
			///////////////////////////////////////////////////////
			//Begin algorithm to insert, check, then delete	for numbers 0 - 9
			/////////////////////////////////////////////////////	
			int result;	
			//First insertion
			for (int insertion1 = 0; insertion1 < length; insertion1++) {
				//After first prime found, we want to test adding
                //a second digit of same type 
				if (count > 0) {
					//Second insertion
					for (int insertion2 = insertion1 + 1; insertion2 < length + 1; insertion2++) {
						//After second prime, test adding in a thrid digit of same type and check for
						//possiblities
						if (count > 1) {
							for (int insertion3 = insertion2 + 1; insertion3 < length + 2; insertion3++) {
								int primes = 0;	
								for (int i = 48; i < 58; i++) {	
									if (insertion1 == 0 && i == 48) {
										i++;
									}
									numberString.insert(numberString.begin() + insertion1, i);
									numberString.insert(numberString.begin() + insertion2, i);	
									numberString.insert(numberString.begin() + insertion3, i);		
									isPrime(sieve, primes, numberString, result);
									if (primes == 8) {
										return result;
									}
									numberString.erase(numberString.begin() + insertion1);
									numberString.erase(numberString.begin() + insertion2 - 1);
									numberString.erase(numberString.begin() + insertion3 - 2);
								}
							}
						}
						else {	
							int primes = 0;	
							for (int i = 48; i < 58; i++) {	
								if (insertion1 == 0 && i == 48) {
									i++;
								}
								numberString.insert(numberString.begin() + insertion1, i);
								numberString.insert(numberString.begin() + insertion2, i);	
							
								isPrime(sieve, primes, numberString, result);
								if (primes == 8) {
									return result;
								}
								numberString.erase(numberString.begin() + insertion1);
								numberString.erase(numberString.begin() + insertion2 - 1);
							}

						}
					}
				}
				else {
					int primes = 0;	
					for (int i = 48; i < 58; i++) {	
						if (insertion1 == 0 && i == 48) {
								i++;
						}
						numberString.insert(numberString.begin() + insertion1, i);	
						isPrime(sieve, primes, numberString, result);
						
						if (primes == 8) {
							return result;
						}			
						numberString.erase(numberString.begin() + insertion1);
					}
				}
			}
	}
	return -1;
}


int main() {
    clock_t time = clock();

    //PRIME SIEVE IMPLEMENTATIOn
    bool *primeSieve = new bool[1000000]();
    const int bound = 1000;
    const int MAX = 1000000;

    //Deal with evens
    int i = 4;
    while (i < MAX) {
	    primeSieve[i] = true;
	    i += 2;
    }
    //Deal with odds
    for (i = 3; i < bound; i += 2) {
	    if ( !primeSieve[i] ) {
		    for (int k = i * 2; k < MAX; k += i) {
			    primeSieve[k] = true;
		    }
	    }
    }

    //Start algorithm
    int result = 0;
    for (int i = 101; i < 999; i += 2) {
	    result = followRules(i, primeSieve);
	    if (result > 0) {
		    break;
	    }   	
    }

    cout << "Answer: " << result << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    delete [] primeSieve;
}

