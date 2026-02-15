class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums)mp[i]++;
        map<int,int>mp1;
        for(auto [a,b]:mp)mp1[b]++;

        for(int x:nums){
            if(mp1[mp[x]]==1)return x;
        }
        return -1;
        
    }
};
