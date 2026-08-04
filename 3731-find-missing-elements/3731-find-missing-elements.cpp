class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx=INT_MIN,mn=INT_MAX;
        unordered_map<int,int>mp;
        for(int c:nums){
            mp[c]++;
            if(c>mx)mx=c;
            if(c<mn)mn=c;
        }
        vector<int>ans;
        for(int i=mn;i<=mx;i++){
            if(mp[i])continue;
            ans.push_back(i);
        }
        return ans;


        
    }
};