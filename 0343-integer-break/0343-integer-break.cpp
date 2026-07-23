class Solution {
    vector<int>dp;
    int dfs(int n){
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, max(i * (n - i), i * dfs(n - i)));
        }
        return dp[n]=ans;

    }
public:
    int integerBreak(int n) {
        dp.resize(n+1,-1);
        return dfs(n);
        
    }
};