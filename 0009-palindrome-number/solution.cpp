class Solution {
public:
    bool isPalindrome(int x) {
        int y=x;
        long int a=0;
        while(y>0){
            a=a*10+y%10;
            y=y/10;
        }
        if(x==a)
        return true;
        else
        return false;
        
    }
};
