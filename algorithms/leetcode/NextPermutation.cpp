#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#define INT_MAX 2147483647

//if it were just a number, we would store the digits placement
//and create a new number, swapping those two digits. Or, we could
//create an algorithm to swap the bits :)

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int starting_index = (int)nums.size() - 2; //safeguard against unsigned integer overflow
        //while numbers are in increasing order
        while (starting_index >= 0 && nums[starting_index] >= nums[starting_index + 1]) {
            starting_index--;
        }
        //if we found a number that broke the while loop, then retreive
        //the next smallest permutation
        if (starting_index >= 0) {
            //Find the smallest number thats bigger than the target
            int target = nums[starting_index];
            int index = nums.size() - 1;
            for (int i = starting_index + 1; i < nums.size() - 1; i++) {
                if (nums[i] < target) {
                    index = i - 1;
                    break;
                }
            }
            swap(nums[index], nums[starting_index]);
            mergeSort(nums, starting_index + 1, nums.size() -1); 
        }
        //sort from beginning to end
        mergeSort(nums, 0, nums.size() - 1);
    }
private:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    //Implement a sorting algorithm :)
    void mergeSort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int mid = (start + end) >> 1;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }
    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> merged(end - start + 2, 0);
        int i = start;
        int j = mid + 1;
        int counter = 0;
        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                merged[counter] = nums[i];
                i++;
            }
            else {
                merged[counter] = nums[j];
                j++;
            }
            counter++;
        }
        while (i <= mid) {
            merged[counter] = nums[i];
            i++;
            counter++;
        }
        while (j <= end) {
            merged[counter] = nums[j];
            j++;
            counter++;
        }
        for (int i = start, j = 0; i <= end; i++, j++) {
            nums[i] = merged[j];
        }
    }
};


int main(int argc, char** argv) {
    vector<int> nums;
    srand(time(NULL));
    for (int i = 0; i < 24; i++) {
        nums.push_back(rand() % 10);
    }
    cout << "Randomly generated number, represented as a vector" << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << endl;
    cout << "Next smallest number, if there is one: " << endl;
    Solution* solution = new Solution;
    solution -> nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << endl;
}
