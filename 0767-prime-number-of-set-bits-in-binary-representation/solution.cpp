class Solution {
public:
    bool isPrime(int n)
    {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
    }

    int countPrimeSetBits(int left, int right) {
        int count=0;
        while(left<=right){
            int a=__builtin_popcount(left);
            if(isPrime(a))count++;
            left++;
        }
        return count;
        
    }
};
