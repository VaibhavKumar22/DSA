class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        vector<int>a;
        for(int x:nums1){
            mp[x]++;
        }
        for(int x:nums2){
            if(mp[x]>0){
                mp[x]--;
                a.push_back(x);
            }
        }
        return a;
        
    }
};
