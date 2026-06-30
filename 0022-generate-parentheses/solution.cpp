class Solution {
public:
    void solve(int o,int c,string s,vector<string>&ans){
        if(o==0 &&c==0){
            ans.push_back(s);
            return;
        }
        if(o>0){
            solve(o-1,c,s+'(',ans);
        }
        if(c>o){
            solve(o,c-1,s+')',ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string t="";
        int o=n,c=n;
        solve(o,c,t,ans);
        return ans;
    }
};
