class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>a;
        for(char c:stones){
            a[c]++;
        }
        int sum=0;
        for(int c:jewels){
            sum+=a[c];
        }
        return sum;
    }
};
