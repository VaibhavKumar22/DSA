#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long maxSubarrays(int n, std::vector<std::vector<int>>& conflictingPairs) {
        // Group conflicting pairs by their right endpoint
        std::vector<std::vector<long long>> right(n);
        for (const auto& p : conflictingPairs) {
            long long l = p[0] - 1, r = p[1] - 1;
            if (l > r) {
                std::swap(l, r);
            }
            right[r].push_back(l);
        }

        long long result = 0;
        // top2 stores the two largest left endpoints of conflicts seen so far
        std::vector<long long> top2(2, -1); 
        // cnt[l] will store the total gain if we remove a conflict starting at l
        std::vector<long long> cnt(n, 0);

        for (int r = 0; r < n; ++r) {
            // Update top2 with the left endpoints of conflicts ending at r
            for (auto l : right[r]) {
                if (l > top2[0]) {
                    top2[1] = top2[0];
                    top2[0] = l;
                } else if (l > top2[1]) {
                    top2[1] = l;
                }
            }

            // A subarray [i, r] is valid if i > top2[0].
            // The number of valid start indices 'i' is from top2[0] + 1 to r.
            // This contributes (r - (top2[0] + 1) + 1) = r - top2[0] valid subarrays ending at r.
            result += (r - top2[0]);

            // If we remove the most restrictive conflict (the one with left endpoint top2[0]),
            // the new restriction becomes top2[1].
            // The gain in valid subarrays ending at r would be (r - top2[1]) - (r - top2[0]) = top2[0] - top2[1].
            if (top2[0] != -1) {
                cnt[top2[0]] += (top2[0] - top2[1]);
            }
        }
        
        long long max_gain = 0;
        if (!cnt.empty()) {
            max_gain = *std::max_element(cnt.begin(), cnt.end());
        }

        return result + max_gain;
    }
};

