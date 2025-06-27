class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m=0;
        int a=0;
        for(int i:gain){
            m+=i;
            a=max(a,m);
        }
        return a;
    }
};
