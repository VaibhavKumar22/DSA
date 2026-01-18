class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;

        for(char a : s) {
            if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') {
                v++;
            }
            else if(a >= 'a' && a <= 'z') {
                c++;   
            }
        }

        if(c > 0) return v / c;
        return 0;
    }
};

