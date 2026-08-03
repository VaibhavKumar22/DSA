class Solution {
    int solve(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>=n)return INT_MAX/2;
        if(i==n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int size=nums[i];
        int mn=INT_MAX/2;
        for(int j=1;j<=size;j++){
            mn=min(mn,1+solve(i+j,n,nums,dp));
        }
        return dp[i]=mn;
    }
public:

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,n,nums,dp);
        
    }
};