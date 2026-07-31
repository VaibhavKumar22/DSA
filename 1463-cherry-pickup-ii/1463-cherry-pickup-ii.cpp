class Solution {
    int solve(int i1,int j1,int i2,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>&dp){

        //bound check or on same [row][col]
        if(i1>=n || i2>=n || j1>=m || j2>=m || j2<0 || j1<0 || (i1==i2 && j1==j2))return INT_MIN;
        //already processed
        if(dp[i1][j1][i2][j2]!=-1)return dp[i1][j1][i2][j2];
        //on last row
        if(i1==n-1 && i2==n-1 && j1!=j2)return grid[i1][j1]+grid[i2][j2];
        int cherry=grid[i1][j1]+grid[i2][j2];
        //rd is right down ,d is down and ld is left down if l_rd then d is for robot 1 and rd is for robot 2
        //robot 1 left down robot 2 all moves
        int ld_ld=solve(i1+1,j1-1,i2+1,j2-1,n,m,grid,dp);
        int ld_d=solve(i1+1,j1-1,i2+1,j2,n,m,grid,dp);
        int ld_rd=solve(i1+1,j1-1,i2+1,j2+1,n,m,grid,dp);
        //robot 1 just dowm robot 2 all moves
        int d_ld=solve(i1+1,j1,i2+1,j2-1,n,m,grid,dp);
        int d_d=solve(i1+1,j1,i2+1,j2,n,m,grid,dp);
        int d_rd=solve(i1+1,j1,i2+1,j2+1,n,m,grid,dp);
        //robot 1 right down robot 2 all moves
        int rd_ld=solve(i1+1,j1+1,i2+1,j2-1,n,m,grid,dp);
        int rd_d=solve(i1+1,j1+1,i2+1,j2,n,m,grid,dp);
        int rd_rd=solve(i1+1,j1+1,i2+1,j2+1,n,m,grid,dp);

        return dp[i1][j1][i2][j2]=cherry+max({ld_ld,ld_d,ld_rd,d_ld,d_d,d_rd,rd_ld,rd_d,rd_rd});

    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<vector<int>>>> dp(
            n,vector<vector<vector<int>>>(m,
            vector<vector<int>>(n,
            vector<int>(m,-1))));
        return solve(0,0,0,m-1,n,m,grid,dp);
    }
};