class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,int>mp;
        for(int a:nums){
            mp[a]=1;
        }
        vector<int> ans;
        for(int i=1;i<=nums.size();i++){
            if(!mp[i])ans.push_back(i);

        }
        return ans;

        
    }
};
