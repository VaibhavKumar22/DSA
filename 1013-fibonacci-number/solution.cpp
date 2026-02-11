class Solution {
public:
    vector<int>dp;
    
    int fibo(int n){
        if(dp[n]!=-1)return dp[n];
        return dp[n]=fibo(n-2)+fibo(n-1);
    }
    int fib(int n) {
        if(n==0)return 0;
        dp.resize(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        int ans=fibo(n);
        return ans;

        
    }
};
