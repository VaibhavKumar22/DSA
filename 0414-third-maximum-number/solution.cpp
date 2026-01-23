class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int i=1;
        int max=nums[0];
        for(int x:nums){
            if(max!=x){
                i++;
                if(i==3){
                    return x;
                }
                max=x;
            }

        }
        if(i<3)max=nums[0];
        return max;


        
    }
};
