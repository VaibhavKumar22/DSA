class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        for(int i: nums1){
            mp[i]=1;
        }
        for(int i: nums2){
            if(mp[i]==1){
                mp[i]=2;
            }
        }
        vector<int> arr;
        for(auto a:mp){
            if(a.second>1)
            arr.push_back(a.first);
        }
        return arr;


        
    }
};
