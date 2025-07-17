#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));
        int res = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;
                for (int prevMod = 0; prevMod < k; ++prevMod) {
                    if (i == 1 || prevMod == mod) {
                        dp[i][mod] = max(dp[i][mod], dp[j][prevMod] + 1);
                        res = max(res, dp[i][mod]);
                    }
                }
            }
        }
        return res;
    }
};

