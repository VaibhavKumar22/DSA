class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>smax(n);
        smax[n-1]=nums[n-1];
        int i=n-2;
        while(i>=0){
            smax[i]=max(nums[i],smax[i+1]);
            i--;
        }
        int suma=0;
        for(int i=0;i<=n-k-1;i++){
            suma=max(suma,(smax[i+k]+nums[i]));
        }
        return suma;
        
    }
};
