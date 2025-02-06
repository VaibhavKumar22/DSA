class Solution {
public:
    int findGCD(vector<int>& nums) {
        // stable_sort(nums.begin(), nums.end());
        int n=nums[0];
        int n1=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<n){
                n=nums[i];
            }
            if(nums[i]>n1){
                n1=nums[i];
            }


        }
        int a;
        for(int i=n;i>0;i--){
            if(n1%i==0&&n%i==0){
                a= i;
                break;
                }

        }
        return a;
        
    }
};
