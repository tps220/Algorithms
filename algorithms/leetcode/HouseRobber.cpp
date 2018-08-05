#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                a = max(b, a + nums[i]);
            }
            else {
                b = max(a, b + nums[i]);
            }
        }
        return max(a, b);
    }

    //Depth First Search Solution, would never use this but a good starting point
    int robDFSsolution(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int first = 0, second = 0;
        robHelper(nums, first, 0, 0);
        robHelper(nums, second, 1, 0);
        if (first > second) {
            return first;
        }
        return second;
    }
private:
    void robHelper(vector<int> &nums, int &retval, int index, int amount) {
        if (index >= nums.size()) {
            if (amount > retval) {
                retval = amount;
            }
            return;
        }
        robHelper(nums, retval, index + 2, amount + nums[index]);
        robHelper(nums, retval, index + 3, amount + nums[index]);
    }
};


int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments" << endl;
        return 1;
    }
    vector<int> nums;
    int idx = 0;
    int current_num = 0;
    while (argv[1][idx] != '\0') {
        if (argv[1][idx] == ',') {
            nums.push_back(current_num);
            current_num = 0;
        }
        else {
            current_num = current_num * 10 + argv[1][idx] - '0';
        }
        idx++;
    }
    nums.push_back(current_num);
    Solution run_method;
    cout << "Obtain a max amount of: " << run_method.rob(nums) << endl;
    return 0; 
}
