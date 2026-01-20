class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=-1,j=-1;
        for(int a=0;a<nums.size();a++){
            if(nums[a]==0){
                i=a;
                j=a+1;
                break;
            }
        }
        if(i==-1)return;
        while(j!=nums.size()){
            if(nums[j]!=0){
                swap(nums[i++],nums[j++]);
            }else{
                j++;
            }
        }
        
        
        
    }
};
