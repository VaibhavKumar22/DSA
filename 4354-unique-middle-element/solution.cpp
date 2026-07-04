class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int c:nums){
            mp[c]++;
        }
        return (mp[nums[nums.size()/2]]==1);
        
    }
};
