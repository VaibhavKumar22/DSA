class Solution {
public:
    int addDigits(int num) {
        if(num<10){
            return num;
        }
        while(num>=10){
            int x=num;
            int sum=0;
            while(x>0){
                sum=sum+x%10;
                x=x/10;
            }
            num=sum;
        }
        return num;
        
    }
};
