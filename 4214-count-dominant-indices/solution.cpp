class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum=0;
        for(int i:nums)sum+=i;

        int count=0;
        
        for(int i=0;i<nums.size()-1;i++){
            sum=sum-nums[i];
            if(sum<nums[i]*(nums.size()-i-1))count++;
        }
        return count;
        
    }
};
