class Solution {
public:
    bool isUgly(int n) {
        if(n<=0){
            return false;

        }
        for(int i=2;i<n;i++){
            if(i>5){
                return false;
            }
            while(n%i==0){
                n=n/i;
            }
        }
        return true;
        
    }
};
