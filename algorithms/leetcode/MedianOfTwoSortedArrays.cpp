#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int iMin = 0, iMax = nums1.size();
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = (m + n + 1) / 2 - i;
            if (i < iMax && j > 0 && nums2[j - 1] > nums1[i]) {
                //this means i has created a split that is bigger on the
                //left half of nums2 vs right half of nums1, so we need to increase it and
                //thereby decrease j
                iMin++;
            }
            else if (i > iMin && j < n && nums1[i - 1] > nums2[j]) {
                //this means that i has created a split that is too big
                //on the left half of nums1 vs right half of nums2, 
                //so we need to decrease it and thereby increasing j
                iMax--;
            }
            //we have created a perfect split, or the boundary condition
            //where i == 0 and j == n, or i == m and j == 0 has occurred
            //which indicates one of the array is completely bigger
            //than the other array and we can go from there
            else {
                //if dealing with an even sequence of numbers,
                //find the average of maxLeft and minRight, otherwise
                //we can just return the maxLeft
                int maxLeft, minRight;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                }
                else if (j == 0) {
                    maxLeft = nums1[i - 1];
                }
                else if (nums1[i - 1] > nums2[j - 1]) {
                    maxLeft = nums1[i - 1];
                }
                else {
                    maxLeft = nums2[j - 1];
                }
                if ((m + n) % 2) {
                    return maxLeft;
                }

                if (i == m) {
                    minRight = nums2[j];
                }
                else if (j == n) {
                    minRight = nums1[i];
                }
                else if (nums1[i] < nums2[j]) {
                    minRight = nums1[i];
                }
                else {
                    minRight = nums2[j];
                } 
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

