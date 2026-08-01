class Solution {
    int dp[101][101][205];

    bool solve(int i, int j, int bal, int n, int m,
               vector<vector<char>>& grid) {

        if (i >= n || j >= m) return false;

        if (grid[i][j] == '(')
            bal++;
        else
            bal--;

        if (bal < 0) return false;

        if (i == n - 1 && j == m - 1)
            return bal == 0;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        bool down = solve(i + 1, j, bal, n, m, grid);
        bool right = solve(i, j + 1, bal, n, m, grid);

        return dp[i][j][bal] = down || right;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Starting ')' cannot form a valid path
        if (grid[0][0] == ')')
            return false;

        // Total path length must be even
        if ((n + m - 1) % 2)
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, n, m, grid);
    }
};