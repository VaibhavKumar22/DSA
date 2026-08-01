class Solution {
    const int MOD = 1e9 + 7;
    int solve(int i, int j, int rem, int n, int m,
              vector<vector<int>>& mat, int k,
              vector<vector<vector<int>>>& dp) {

        rem = (rem + mat[i][j]) % k;

        if (i == n - 1 && j == m - 1)
            return rem == 0;

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        long long ans = 0;
        if(i + 1 < n)ans += solve(i + 1, j, rem, n, m, mat, k, dp);
        if(j + 1 < m)ans += solve(i, j + 1, rem, n, m, mat, k, dp);
        return dp[i][j][rem] = ans % MOD;
    }

public:
    int numberOfPaths(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k, -1)));

        return solve(0, 0, 0, n, m, mat, k, dp);
    }
};