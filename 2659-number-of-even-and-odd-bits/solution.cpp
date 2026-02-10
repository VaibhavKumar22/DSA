class Solution {
public:
    vector<int> evenOddBit(int n) {
        int i=0;
        int eveni=0;
        int oddi=0;
        while(n){
            if((n&1)==1){
                if((i&1)==0)eveni++;
                else oddi++;
            }
            i++;
            n>>=1;
        }
        return {eveni,oddi};
        
    }
};
