class Solution {
public:
    int hammingDistance(int x, int y) {
        // int count=0;
        // while(x||y){
        //     int i=x&1;
        //     int j=y&1;
        //     if(i!=j)count++;
        //     x>>=1;
        //     y>>=1;

        // }
        // return count;
        int a=x^y;
        return __builtin_popcount(a);
        
    }
};
