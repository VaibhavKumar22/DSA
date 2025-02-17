class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> a={-1,-1};
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                a[0]=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                a[1]=i;
                break;
            }
        }
        return a;

        
    }
};
