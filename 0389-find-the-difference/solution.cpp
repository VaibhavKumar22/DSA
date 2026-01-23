class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>mp;
        for(char c:s)mp[c]++;
        for(char c:t){
            if(!mp[c]||mp[c]==0)return c;
            mp[c]--;
        }
        return ' ';
        
    }
};
