class Solution {
public:
    int getSum(int a, int b) {
        if(b>0){
        while(b>0){
            a++;
            b--;
        }
        return a;}
        while(b<0){
            a--;
            b++;
        }
        return a;
        
    }
};
