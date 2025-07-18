#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int total_len = nums.size();

        // Prefix sums for smallest n elements in first 2n elements
        priority_queue<int> maxHeap;
        long long leftSum = 0;
        vector<long long> prefixSums(2 * n);

        for (int i = 0; i < 2 * n; ++i) {
            maxHeap.push(nums[i]);
            leftSum += nums[i];
            if (maxHeap.size() > n) {
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }
            prefixSums[i] = leftSum;
        }

        // Suffix sums for largest n elements in last 2n elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightSum = 0;
        vector<long long> suffixSums(2 * n);

        for (int i = total_len - 1; i >= n; --i) {
            minHeap.push(nums[i]);
            rightSum += nums[i];
            if (minHeap.size() > n) {
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            suffixSums[i - n] = rightSum;
        }

        // Calculate the minimum difference
        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            res = min(res, prefixSums[i] - suffixSums[i - n + 1]);
        }

        return res;
    }
};

