class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int i=nums[0];
        int j=nums[n-1];
        return (i>j)?i:j;
        
    }
};
