class Solution {
    int solve(int i, vector<int>& points, vector<int>& dp) {
        if (i < 0)
            return 0;

        if (i == 0)
            return points[0];

        if (dp[i] != -1)
            return dp[i];

        int take = points[i] + solve(i - 2, points, dp);
        int skip = solve(i - 1, points, dp);

        return dp[i] = max(take, skip);
    }

public:
    int deleteAndEarn(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> points(mx + 1, 0);

        for (int x : nums)
            points[x] += x;

        vector<int> dp(mx + 1, -1);

        return solve(mx, points, dp);
    }
};