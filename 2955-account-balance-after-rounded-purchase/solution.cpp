class Solution {
public:
    int accountBalanceAfterPurchase(int p) {
        int n=p%10;
        if(n<5){
            return 100-(p-n);
        }
        return 100-(p+(10-n));
        
    }
};
