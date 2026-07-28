class Solution {

public:
    int solve(int i,int j,int i2,int j2,vector<vector<int>>& grid,int n, vector<vector<vector<vector<int>>>>&dp){
        if(i>=n||j>=n||i2>=n||j2>=n||grid[i2][j2]==-1||grid[i][j]==-1)return -1000000000;

        if(dp[i][j][i2][j2]!=-1)return dp[i][j][i2][j2];

        if(i==n-1&&j==n-1&&i2==n-1&&j2==n-1)return grid[i][j];
        int cherry=grid[i][j];
        if(i!=i2||j!=j2)cherry+=grid[i2][j2];
        int case1=solve(i+1,j,i2,j2+1,grid,n,dp);  
        int case2=solve(i+1,j,i2+1,j2,grid,n,dp);  
        int case3=solve(i,j+1,i2,j2+1,grid,n,dp);  
        int case4=solve(i,j+1,i2+1,j2,grid,n,dp);  
        
        return dp[i][j][i2][j2]=cherry+max({case1,case2,case3,case4});
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
          vector<vector<vector<vector<int>>>> dp(
            n,vector<vector<vector<int>>>(n,
                vector<vector<int>>(n,
                    vector<int>(n,-1))));
        return max(0,solve(0,0,0,0,grid,n,dp));


        
    }
};