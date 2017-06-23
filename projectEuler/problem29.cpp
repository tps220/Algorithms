//This one can be done by hand and then written step by step into the program if you
//would so desire. I would rather do this than the brute force method
//because its much more creative and does not require using
//very large number (hence 100 ^ 100).
//
//
//This is how one would do the way by hand:
//If we are only looking at the powers of numbers from 1 to 100,
//we want to break down all the possible numbers that can be raised to a power by another smaller
//number. We have a max of 99*99 possible distinct numbers since we are raising from base a = 2 to 100
//and expnent b = 2 to 100. So, all the small numbers that can represent large numbers are as follow:
//
//2^power:	4	8	16	32	64	//don't include 128 since more than 100
//3^powwr:	9	27	81
//4^power:	16	64
//5^power:	25
//6^power:	36
//7^power:	49
//8^power:	64
//9^power:	81
//10^power:	100
//
//
//Our algorithm should disitincly remove future duplicates, so when 2^2 gets implemented, we check for all the
//duplicates where 4^some power will produce the same number as 2^2.
//However, we must also account that some duplicates will have already been checked by a previous smaller base
//and not checked in some occurences by a bigger base.
//
//What that means is:
//2^4 = 16..... so (2^4) ^ b = 16 ^ b.
//however, 4 ^ 2 = 16.... so (4^2) ^ b = 16 ^ b.
//Since base 4 to the 100 can go higher than base 2 to the 100, we will use both to check all duplicates
//for base 16 and its powers to 100.
//



#include <iostream>
#include <time.h>
#include <set>
#include <cmath> 
using namespace std;



int main() {


clock_t time = clock();
int MAX_POSSIBILITIES = 99 * 99; //99 * 99 total numbers created
int duplicates = 0;

//Occurences of Squares Taken Step By Step:



//Distinct Number to Power of 2 (6)
//4 = 2^2 --> 4^p = (2^2)^p --> 2 ^ 4 to 2 ^ 100 incrementing by two = 49 duplicates
//9 = 3^2 
//25 = 5^2
//36 = 6^2
//49 = 7^2 
//100 = 10^2 

duplicates += 49 * 6;




//Distinct Number to Power of 3 (2)
//8 = 2^3 --> 8^p = (2^3)^p --> 2^6 to 2^ 100 incrementing by three --> 32 duplicates
//8^p can be intersected by 4^3 = (2^2) ^3 so just in increasing the range of the last and incrementing by
//six rather than 3, we see 4 ^ 3 to 4 ^ 100 incrementing by three and not counting last times duplicates,
//it comes out to --> 17 duplicates (increasing the range by two, but already counted 2/3 of duplicates)
//27 = 3^3

duplicates += (32 + 17) * 2;

//Distinct Number to Power of 5(1)
//32 = 2^5 --> 32 ^ p = (2^5) ^ p --> 2^10 to 2^100 incrementing by three --> 19 duplicates
//32 can be intersected by 4^5 = (2^2) ^ 5 --> increasing the range again x2 --> 10 duplicates
//32 can be intersected by 8^5 = (2^3) ^ 5 --> increasing the range again x3 --> 11 duplicates
//32 can be intersected by 16^5 = (2^4) ^ 5 --> incerasing the range again x4 --> 8 duplicates
//
duplicates += 19 + 10 + 11 + 8;

//Numbers with square powers (2)
//16 = 4^2, 2^4 --> 16^p = 2^4^p --> 2^8 to 2^100 incrementing by four --> 24 duplciates
//16 can be intersected by 4^2 = (2^2)^2 --> increase range x2, increment by 2--> 4 ^ 50 to 4 ^ 100 --> 26 duplicates
//16 can be intersected by 8^2 = (2^3) ^ 2 --> increasin range x2 increment by 6 --> 8 ^ 52  to 5^100 --> 8 duplicates
//81 = 9^2, 3^4

duplicates += (24 + 26 + 8) * 2;

//Numbers with all other powers(1)
//64 = 2^6, 4^3, 8^2 --> 8^2 --> 49 duplicates
//64 can be intersected by 16^2 = (2^4) ^ 2 --> increasing range by 2 --> 8 duplicates
//64 can be intersected by 32^2 =(2^5) ^ 2 --> increasing range by 2  --> 5 duplicates
duplicates += 49 + 5 + 8;


cout << "Answer: " << MAX_POSSIBILITIES - duplicates << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
};
