class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i:nums){
            total+=i;
        }
        int ltotal=0;
        for(int i=0;i<n;i++){
            if(ltotal==total-ltotal-nums[i]){
                return i;
            };
            ltotal+=nums[i];
        }
        return -1;
        

        
    }
};
