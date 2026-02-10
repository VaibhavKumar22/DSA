class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        unsigned int n = num;  // handles negative via 2's complement
        string res = "";
        string hex = "0123456789abcdef";
        
        while (n) {
            res += hex[n & 15];   // last 4 bits
            n >>= 4;              // shift by 4 bits
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
