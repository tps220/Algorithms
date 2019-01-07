#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    MinStack(): values(vector<int>()), minimum_val(vector<int>()) {}

    void push(int x) {
        values.push_back(x);
        if (minimum_val.size() == 0 || x < minimum_val[minimum_val.size() - 1]) {
            minimum_val.push_back(x);
        }
        else {
            minimum_val.push_back(minimum_val[minimum_val.size() - 1]);
        }
    }

    void pop() {
        if (values.size() > 0) {
            values.pop_back();
            minimum_val.pop_back();
        }
    }

    int top() {
        if (values.size() > 0) {
            return values[values.size() - 1];
        }
        return 0;
    }

    int getMin() {
        if (minimum_val.size() > 0) {
            return minimum_val[minimum_val.size() - 1];
        }
        return 0;
    }
private:
    vector<int> minimum_val;
    vector<int> values;
};
