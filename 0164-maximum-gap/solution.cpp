class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max1=0;
        int i=0;
        int j=i+1;
        while(j<nums.size()){
            max1=max(max1,nums[j++]-nums[i++]);
        }
        return max1;
        
    }
};
