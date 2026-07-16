class Solution {
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>premax(n,0);
        premax[0]=nums[0];
        for(int i=1;i<n;i++){
            premax[i]=max(nums[i],premax[i-1]);
        }
        vector<int>prefixgcd(n);
        for(int i=0;i<n;i++){
            prefixgcd[i]=gcd(nums[i],premax[i]);
        }

        sort(prefixgcd.begin(),prefixgcd.end());
        long long sum=0;
        int left=0,right=n-1;
        while(left<right){
            sum=sum+1LL*gcd(prefixgcd[left],prefixgcd[right]);
            left++;right--;
        }
        return sum;


        
    }
};