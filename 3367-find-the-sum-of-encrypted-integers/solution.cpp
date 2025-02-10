class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int a=0;
            int b=nums[i];
            while(b>0){
                int c=b%10;
                if(c>a){
                    a=c;
                }
                b=b/10;
            }
            while(nums[i]>0){
                b=b*10+a;
                nums[i]=nums[i]/10;

            }
            sum=sum+b;
        }
        return sum;
        
    }
};
