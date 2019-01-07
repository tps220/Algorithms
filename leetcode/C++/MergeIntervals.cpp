#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return vector<Interval>();
        }
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start <= b.start;});
        vector<Interval> output;
        output.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (output.back().end >= intervals[i].start) {
                output.back().end = max(intervals[i].end, output.back().end);
            }
            else {
                output.push_back(intervals[i]);
            }
        }
        return output;
    }
};
