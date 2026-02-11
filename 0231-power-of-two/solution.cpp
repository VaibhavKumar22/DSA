class Solution {
public:
    bool check(int n){
        if(n<2||n%2!=0)return false;
        if(n==2)return true;
        
        bool ans=check(n/2);
        return ans;
        
    }
    bool isPowerOfTwo(int n) {
        // return (n>0&&(n&(n-1))==0)?true:false;
        
        if(n==1)return true;
        if(n<2||n%2!=0)return false;
        if(n==2)return true;
        return isPowerOfTwo(n/2);

    }
};
