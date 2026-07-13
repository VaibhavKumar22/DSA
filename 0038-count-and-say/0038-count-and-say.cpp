class Solution {
public:
    vector<string>dp;
    string dfs(int n) {
        if (dp[n] != "") return dp[n];
        string prev = dfs(n - 1);
        string ans ="";
        int cnt = 1;
        for (int i = 1; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1]) {
                cnt++;
            } else {
                ans += to_string(cnt);
                ans += prev[i - 1];
                cnt = 1;
            }
        }
        ans += to_string(cnt);
        ans += prev.back();
        return dp[n] = ans;
    }
    string countAndSay(int n) {
        dp.resize(n+1);
        dp[1]="1";
        dfs(n);
        return dp[n];
        
    }
};