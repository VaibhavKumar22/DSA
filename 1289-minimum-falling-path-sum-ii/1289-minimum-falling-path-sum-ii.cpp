class Solution {
    int solve(int i,int j,int n,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i>=n||j>=n||j<0)return INT_MAX;
        // if(j1==j)return INT_MAX;


        if(dp[i][j]!=INT_MAX)return dp[i][j];
        if(i==n-1)return dp[i][j]=grid[i][j];
        int mn=INT_MAX;
        for(int k=0;k<n;k++){
            if(k==j)continue;
            mn=min(mn,solve(i+1,k,n,grid,dp));
        }
        return dp[i][j]=grid[i][j]+mn;

    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mn=min(mn,solve(0,i,n,grid,dp));
        }
        return mn;

        
    }
};