class Solution {
public:

    int climbStairs(int n) {
        int temp=0;
        int temp2=1;
        int res=0;
        for(int i=0;i<n;i++){
            res=temp+temp2;
            temp=temp2;
            temp2=res;
        }
        return res;

    }
};
