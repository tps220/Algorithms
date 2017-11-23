//Thomas Salemy
//Project Euler Solutions
//Problem 68

#include <iostream>


//To get the biggest possible 16 digit string, we need 10, 9, 8, 7, 6
//on the outside.
//Since each number on the inside of the ring is in two sequences,
//it is counted twice. Given this knowledge,
//the total sum of the 5 groups to give the biggest possible
//16 digit string is (10 + 9 + 8 + 7 + 6) + 2 * (5 + 4 + 3 + 2 + 1) = 70
//Each group, therefore, must sum to 70 / 5 = 14. Now, just find the numbers that keep
//follow the rules and create the maximum number...
//
//Solution:
//6 5 3  -> 14
//10 3 1 -> 14
//9 1 4  -> 14
//8 4 2  -> 14
//7 2 5  -> 14
int main() {
    std::cout << 6531031914842725 << std::endl;
}
