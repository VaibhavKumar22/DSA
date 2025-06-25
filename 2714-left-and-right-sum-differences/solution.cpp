class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>pf(nums.size(),0);
        vector<int>sf(nums.size(),0);
        for(int i=1;i<nums.size();i++){
            pf[i]=pf[i-1]+nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            sf[i]=sf[i+1]+nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            pf[i]=abs(pf[i]-sf[i]);
        }
        return pf;

        
    }
};
