class Solution {
public:
    int findComplement(int n) {
        if (n == 0) return 1;
        int ans=0;
        int i=0;
        while(n){
            if((n&1)==0){
                ans =ans| (1<<(i));
            }
            i++;
            n>>=1;
        }
    return ans;
    }
};
