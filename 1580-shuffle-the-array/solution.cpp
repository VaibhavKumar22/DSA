class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0;
        int j=n;
        int k=0;
        vector<int> arr(nums.size());
        while(j<nums.size()){
            arr[k++]=nums[i++];
            arr[k++]=nums[j++];
        }
        return arr;
        
    }
};
