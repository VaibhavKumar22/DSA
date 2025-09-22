#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Find maximum frequency
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        // Count total elements having frequency = maxFreq
        int result = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq)
                result += p.second;
        }

        return result;
    }
};


