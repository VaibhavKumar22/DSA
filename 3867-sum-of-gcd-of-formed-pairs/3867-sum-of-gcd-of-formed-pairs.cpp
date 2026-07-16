class Solution {
    
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        // int n=nums.size();
        // int mx=INT_MIN;
        
        // vector<int>prefixgcd(n);
        // for(int i=0;i<n;i++){
        //     mx=max(mx,nums[i]);
        //     prefixgcd[i]=gcd(nums[i],mx);
        // }
        // sort(prefixgcd.begin(),prefixgcd.end());
        // long long sum=0;
        // int left=0,right=n-1;
        // while(left<right){
        //     sum=sum+1LL*gcd(prefixgcd[left],prefixgcd[right]);
        //     left++;right--;
        // }
        // return sum;
        int xMax=0, n=nums.size();
        for(int& x: nums){
            xMax=max(x, xMax);
            x=gcd(x, xMax);
        }
        sort(nums.begin(), nums.end());
        long long sum=0;
        for(int l=0, r=n-1; l<r; l++, r--)
            sum+=gcd(nums[l], nums[r]);
        return sum;


        
    }
};