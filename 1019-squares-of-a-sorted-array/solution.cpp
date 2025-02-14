class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>a={};
        for(int i=0;i<nums.size();i++){
            a.push_back(nums[i]*nums[i]);
        }
        stable_sort(a.begin(),a.end());
        return a;

        
    }
};
