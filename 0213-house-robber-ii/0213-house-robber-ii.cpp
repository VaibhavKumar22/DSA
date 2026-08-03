class Solution {
    int solve(int i, int n, vector<int>& nums, vector<int>& dp)
    {
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i + 2, n, nums, dp);
        int nottake = solve(i + 1, n, nums, dp);

        return dp[i] = max(take, nottake);
    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> first(nums.begin(), nums.end() - 1);
        vector<int> second(nums.begin() + 1, nums.end());

        vector<int> dp1(first.size(), -1);
        vector<int> dp2(second.size(), -1);

        int case1 = solve(0, first.size(), first, dp1);
        int case2 = solve(0, second.size(), second, dp2);

        return max(case1, case2);
    }
};