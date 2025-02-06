class Solution {
public:
    bool isSameAfterReversals(int x) {
        if(x==0){
            return true;
        }else if(x%10==0){
            return false;
        }
        else{
            int y=x;
            int sum=0;
            while(y>0){
                sum=sum*10+y%10;
                y=y/10;
            }
            int a=sum;
            int sum1=0;
            while(a>0){
                sum1=sum1*10+a%10;
                a=a/10;
            }
            if(sum1==x){
                return true;
            
            }
            else{
                return false;
            }

        }
        
    }
};
