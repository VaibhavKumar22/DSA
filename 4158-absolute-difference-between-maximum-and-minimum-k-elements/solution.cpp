class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sumsmall=0;
        int c=k;
        while(c--){
            sumsmall+=nums[c];
        }
        c=nums.size()-k;
        int bigsum=0;
        while(c<nums.size()){
            bigsum+=nums[c++];

        }
        return abs(sumsmall-bigsum);
    }
};
