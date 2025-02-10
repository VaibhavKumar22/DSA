class Solution {
public:
    int smallestNumber(int n, int t) {
        int a=1;
        int b=n;
        while(b>0){
            a=a*(b%10);
            b=b/10;
        }
        if(a%t==0){
            return n;
        }
        int m=smallestNumber(n+1,t);
        return m;
        

}
};
