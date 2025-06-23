class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxEnd=nums[0];
        int res=nums[0];
        int i=1;
        while(i<n){
            if(maxEnd<0){
                maxEnd=nums[i];
            }
            else{
                maxEnd=maxEnd+nums[i];
            }
            res=max(maxEnd,res);
            i++;
        }
        return res;
        
    }
};
