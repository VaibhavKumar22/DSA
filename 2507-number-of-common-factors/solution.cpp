class Solution {
public:
    int commonFactors(int a, int b) {
        int c;
        if(a>b){
            c=b;
        }
        else{
            c=a;
        }
        int count=0;
        for(int i=1;i<=c;i++){
            if(a%i==0&&b%i==0){
                count++;
            }
        }
        return count;
        
    }
};
