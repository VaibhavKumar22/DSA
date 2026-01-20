class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i:nums){
            if(mp[i]){
                return true;
            }
            mp[i]++;
            
        }
        return false;
        
    }
};
