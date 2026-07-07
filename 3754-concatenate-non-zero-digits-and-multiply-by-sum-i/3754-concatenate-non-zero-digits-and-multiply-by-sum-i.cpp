class Solution {
public:
    long long sumAndMultiply(int n) {
        int newnum=0;
        int i=0;
        int sum=0;
        while(n>0){
            int digit=n%10;
            if(digit!=0){
                newnum=newnum+digit*pow(10,i);
                i++;
                sum+=digit;
            }
            n/=10;
        }
        return 1LL* newnum*sum;
        
    }
};