class Solution {
    int solve(int i,int j,int prev,int n, int m, vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i>=n||j>=m||i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(prev>=grid[i][j])return 0;
        int upright=solve(i-1,j+1,grid[i][j],n,m,grid,dp);
        int right=solve(i,j+1,grid[i][j],n,m,grid,dp);
        int downright=solve(i+1,j+1,grid[i][j],n,m,grid,dp);
        return dp[i][j]=1+max({upright,right,downright});
    }
public:

    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mx=1;
        for(int i=0;i<n;i++){
            mx=max(mx,solve(i,0,INT_MIN,n,m,grid,dp));
        }
        return mx-1;
        
    }
};