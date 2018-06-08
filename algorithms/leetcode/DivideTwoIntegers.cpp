#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define INT_MAX 2147483647

class Solution {
public:
    int divide(int dividend_input, int divisor_input) {
        if (divisor_input == 0 || dividend_input == 0) {
            return 0;
        }
        int sign = 1;
        int mask = 1 << 31;
        if (dividend_input & mask ^ divisor_input & mask) {
            sign = -1;
        }
        long divisor = abs((long)divisor_input);
        long dividend = abs((long)dividend_input);
        long count = 0;
        while (dividend > 0) {
            long current_count = 0;
            long sum;
            for (sum = divisor; sum <= dividend; sum += sum) {
                if (current_count == 0) {
                    current_count = 1;
                }
                else {
                    current_count += current_count;
                }
                if (sum + sum > dividend) {
                    break;
                }
            }
            count += current_count;
            if (sum == dividend) {
                count = count * sign;
                if (count > INT_MAX) {
                    return INT_MAX;
                }
                return count;
            }
            else if (sum == 0) {
                break;
            }
            dividend -= sum;
        }
        count = count * sign;
        if (count > INT_MAX) {
            return INT_MAX;
        }
        return count;
    }
};


int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Only provided " << argc << " arguments, need 3" << endl;
        return 1;
    }
    int dividend = atoi(argv[1]);
    int divisor = atoi(argv[2]);
    Solution* solution = new Solution;
    int answer = solution -> divide(dividend, divisor);
    int calculated = 0;
    if (dividend && divisor) {
        calculated = dividend / divisor;
    }
    cout << "Answer: " << answer << endl;
    cout << "Expected Answer: " << calculated << endl;
    if (answer != calculated) {
        cout << "FAILED" << endl;
    }
    else {
       cout <<  "PASSED" << endl; 
    }
    return 1;
}
