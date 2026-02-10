class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i=-1;
        while(n){
            if(i==(n&1))return false;
            i=n&1;
            n>>=1;

        }
        return true;
    }
};
