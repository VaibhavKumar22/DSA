class Solution {
public:
    int countDigits(int num) {
        if(num<10){
            return 1;
        }
        int n=num;
        long int count =0;
        while(n>0){
            int a=n%10;
            if(num%a==0){
                count++;
            }
            n=n/10;
        }
        return count;
        
    }
};
