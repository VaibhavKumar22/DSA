class Solution {
    vector<int> dp;

    int dfs(int i, vector<int>& cost) {
        if (i == 0) return cost[0];
        if (i == 1) return cost[1];

        if (dp[i] != -1) return dp[i];

        return dp[i] = min(dfs(i - 1, cost), dfs(i - 2, cost)) + cost[i];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n, -1);

        return min(dfs(n - 1, cost), dfs(n - 2, cost));
    }
};
