class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int ans=1e8;
        while(i<nums.size()){
            sum+=nums[i];
            while(sum>=target&&j<=i){
                ans=min(ans,i-j+1);
                sum-=nums[j++];
            }
            i++;
        }
        return ans==1e8?0:ans;

    }
};
