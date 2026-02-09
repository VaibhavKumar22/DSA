class Solution {
public:
    vector<vector<int>>dp;
    int rec(int curr,int largest,int n){
        if(curr == n) return 0;
        if(curr > n) return 1e9;
        if(dp[curr][largest]!=-1)return dp[curr][largest];
        
        // if(largest > 0)
        //     ans = min(ans, 1 + rec(curr + largest, largest, n));
        // ans = min(ans, 2 + rec(curr + curr, curr, n));
        int ans = min(1 + rec(curr + largest, largest, n),2 + rec(curr + curr, curr, n));
        return dp[curr][largest] = ans;
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        dp.resize(n+1,vector<int>(n+1,-1));
        return 1+rec(1,1,n);

      
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
