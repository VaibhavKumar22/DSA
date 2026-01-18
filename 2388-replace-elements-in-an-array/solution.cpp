class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& o) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }

        for(int i = 0; i < o.size(); i++){
            int oldVal = o[i][0];
            int newVal = o[i][1];

            int idx = mp[oldVal];
            nums[idx] = newVal;

            mp.erase(oldVal);
            mp[newVal] = idx;
        }

        return nums;
    }
};


