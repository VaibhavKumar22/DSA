class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        int sum1=0;
        for(int i=0;i<nums.size();i++){
            int c=nums[i];
            sum+=c;
            while(c>0){
                sum1+=c%10;
                c=c/10;
            }
        }
        if(sum>sum1){
            return sum-sum1;
        }
        else{
            return sum1-sum;
        }

        
    }
};
