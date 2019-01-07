#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string retval = "1";
        if (n <= 1) {
            return retval;
        }
        for (int i = 1; i < n; i++) {
            complete(retval);
        }
        return retval;
    }
private:
    void complete(string &sequence) {
        string curr = "";
        int count = 0;
        char previous = sequence[0];
        for (int i = 0; i < sequence.length(); i++) {
            char ch = sequence[i];
            if (ch == previous) {
                count++;
            }
            else {
                curr.push_back('0' + count);
                curr.push_back(previous);
                previous = ch;
                count = 1;
            }
        }
        curr.push_back('0' + count);
        curr.push_back(previous);
        sequence.swap(curr);
    }
};
