class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0,j=i+1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                ans=nums[i];
                break;
            }
            i++;
            j++;
        }
        return ans;


    }
};

