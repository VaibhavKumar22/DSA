class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int y) {
        int sum=0;
        int x=y;
        while(x>0){
            sum=sum+x%10;
            x=x/10;
        }
        if(y%sum==0){
            return sum;
        }
        return -1;
        
    }
};
