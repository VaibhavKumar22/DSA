class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if(grid[0][0] == 1) return 0;
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size(), n = grid[0].size();

        if (i >= m || j >= n || grid[i][j] == 1)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = solve(i + 1, j, grid, dp) +
                          solve(i, j + 1, grid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, grid, dp);
    }
};
        dp[0][0] = 1;

        // First column
        for(int i = 1; i < m; i++){
            if(grid[i][0] == 0)
                dp[i][0] = dp[i-1][0];
        }

        // First row
        for(int j = 1; j < n; j++){
            if(grid[0][j] == 0)
                dp[0][j] = dp[0][j-1];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){

                if(grid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
