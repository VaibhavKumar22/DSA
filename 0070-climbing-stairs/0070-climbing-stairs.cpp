class Solution {
    vector<int>dp;
    int dfs(int n){
        if(n<=1)return 1;
        // if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int l=dfs(n-2);
        int r=dfs(n-1);
        return dp[n]=l+r;


    }
public:

    int climbStairs(int n) {
        // int temp=0;
        // int temp2=1;
        // int res=0;
        // for(int i=0;i<n;i++){
        //     res=temp+temp2;
        //     temp=temp2;
        //     temp2=res;
        // }
        // return res;
        dp.resize(n+1,-1);
        return dfs(n);

    }
};