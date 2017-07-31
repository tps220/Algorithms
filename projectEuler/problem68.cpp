#include <iostream>


int main() {
//Answered this problem by hand....
//
//
//The rule that gives us the biggest help in this problem is how
//the smallest number in the outer-ring starts us off, therefore,
//to get the biggest possible 16 digit string, we need 10, 9, 8, 7, 6
//on the outside.
//
//Since each number on the inside of the ring is in two sequences....
//the total sum of the 5 groups will be (10 + 9 + 8 + 7 + 6) + 2 * (5 + 4 + 3 + 2 + 1) = 70
//
//Each group, therefore, must sum to 70 / 5 = 14. Now, just find the numbers that keep
//on following the rules and make the maximum number....
//
//
//it goes:
//6 5 3    -> 14
//   -> 14
//9 1 4    -> 14
//8 4 2    -> 14
//7 2 5    -> 14

std::cout << 6431031914842725 << std::endl;

}
