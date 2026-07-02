class Solution {
public:
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b); 
    }
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
        int a=gcd(n,n1);
        return a;
        
    }
};
