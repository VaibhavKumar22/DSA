class Solution {
    int solve(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(i>=n||j>=n||j<0)return INT_MAX;
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        if(i==n-1)return dp[i][j]=matrix[i][j];

        int leftdown=solve(i+1,j-1,n,matrix,dp);
        int down=solve(i+1,j,n,matrix,dp);
        int rightdown=solve(i+1,j+1,n,matrix,dp);
        return dp[i][j]=matrix[i][j]+min({leftdown,down,rightdown});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mn=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            mn=min(mn,solve(0,i,n,matrix,dp));
        }
        return mn;
        
    }
};