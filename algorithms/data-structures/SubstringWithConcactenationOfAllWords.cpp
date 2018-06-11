#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> retval;
        //if an empty number of words
        if (words.size() == 0) {
            return retval;
        }
        //if the words won't fit into the length of the string
        else if (words[0].length() * words.size() > s.length()) {
            return retval;
        }
        
        //store a dictionary of the words' frequency
        unordered_map<string, int> dict;
        for (size_t i = 0; i < words.size(); i++) {
            dict[words[i]]++;
        }
        
        int width = words[0].length();
        for (int i = 0; i < width; i++) {
            //create a sliding window, that stores both the current
            //count of the number of words seen from our dictionary above
            //in the variable count and the frequency of that word in the current
            //window inside a local dictionary that gets dynamically updated
            size_t starting_index = i, count = 0;
            unordered_map<string, int> local_dict;
            //loop through the current window, starting at the current offset i
            for (int j = i; j <= (int)s.length() - width; j += width) {
                //get the current string to be checked
                string buffer = s.substr(j, width);
                //if the substring is one of the words, update the variables
                //that are recording information about the current window
                if (dict.find(buffer) != dict.end()) {
                    local_dict[buffer]++;
                    count++;
                    //check for duplicate words that are distorting the count
                    if (local_dict[buffer] > dict[buffer]) {
                        count--;
                        //going through all the words in the current window
                        //before the duplicate, and removing them from the local dictionary as
                        //we update the position of the current window
                        while (local_dict[buffer] > dict[buffer]) {

                            string past_buffer = s.substr(starting_index, width);
                            local_dict[past_buffer]--;
                            //when the duplicate is finally dealt with, this
                            //allows us to take care of the edge condition
                            //where we wouldn't decrement the count because
                            //the local_dict[past_buffer] would now == dict[past_buffer]
                            if (local_dict[past_buffer] < dict[past_buffer]) {
                                count--;
                            }
                            starting_index += width;
                        }
                    }
                    //if the current count equals the number of words,
                    //we have found a sequence! Store it in the array
                    //we will return at the end of the loop and update
                    //the window
                    if (count == words.size()) {
                        retval.push_back(starting_index);
                        local_dict[s.substr(starting_index, width)]--;
                        count--;
                        starting_index += width;
                    }
                }
                //if the substring is not one of the words, reset the window
                //and the variables storing information about our window
                else {
                    count = 0;
                    local_dict.clear();
                    starting_index = j + width;
                }
            }
        }
        return retval;
    }
};
