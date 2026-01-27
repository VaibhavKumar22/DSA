class Solution {
public:
    int subarraySum(vector<int>& nums, int x) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for(int num : nums) {
            prefixSum += num;

            if(mp.find(prefixSum - x) != mp.end())
                count += mp[prefixSum - x];

            mp[prefixSum]++;
        }

        return count;
        
        
        
    }
};
