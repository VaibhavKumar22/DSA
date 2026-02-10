class Solution {
public:
    int binaryGap(int n) {
        int dis = 0;
        int i = 0;    
        int j = -1;    

        while (n) {
            if (n & 1) {           
                if (j != -1) {
                    dis = max(dis, i - j);
                }
                j = i;             
            }
            i++;
            n >>= 1;
        }
        return dis;
    }
};

