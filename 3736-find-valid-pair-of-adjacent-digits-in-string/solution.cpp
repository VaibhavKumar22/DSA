class Solution {
public:
    string findValidPair(string s) {
        map<int,int> mp;
        for(char c : s)mp[c - '0']++;
        
        for(int i = 0; i < s.size() - 1; i++) {
            int a = s[i] - '0';
            int b = s[i+1] - '0';

            if(a != b && mp[a] == a && mp[b] == b) {
                return s.substr(i, 2);  // first valid pair
            }
        }

        return "";
    }
};

