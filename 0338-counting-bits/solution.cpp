class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        while(n>=0){
            ans[n--]=__builtin_popcount(n);
        }
        return ans;

        
        
    }
};
