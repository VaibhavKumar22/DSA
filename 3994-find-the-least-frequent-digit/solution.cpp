class Solution {
public:
    unordered_map<int,int>mp;
    void mapping(int n){
        while(n>0){
            mp[n%10]++;
            n/=10;
        }
    }
    int getLeastFrequentDigit(int n) {
        mapping(n);
        int frq=INT_MAX;
        int frqdigit=INT_MAX;
        for(auto [digit,freq]:mp){
            if(frq>=freq){
                if(frq==freq){
                    frqdigit=(frqdigit<digit)?frqdigit:digit;
                    continue;
                }
                frq=freq;
                frqdigit=digit;
            }

        }
        return frqdigit;

    }
};
