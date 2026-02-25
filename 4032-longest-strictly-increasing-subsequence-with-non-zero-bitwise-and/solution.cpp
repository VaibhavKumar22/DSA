class Solution {
public:
    
    int LIS(vector<int>& arr) {
        vector<int> dp;
        
        for(int x : arr) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if(it == dp.end()) {
                dp.push_back(x);
            } else {
                *it = x;
            }
        }
        
        return dp.size();
    }
    
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bit = 0; bit < 32; bit++) {
            vector<int> filtered;
            
            for(int i = 0; i < n; i++) {
                if(nums[i] & (1 << bit)) {
                    filtered.push_back(nums[i]);
                }
            }
            
            if(!filtered.empty()) {
                ans = max(ans, LIS(filtered));
            }
        }
        
        return ans;
    }
};
