class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        map<char,int> n;
        for(char a:s){
            n[a]++;
        }
        for(char a:t){
            if(n[a]&&n[a]>0){
                n[a]--;
            }
            else{
                return false;
            }
        }
        return true;

        
    }
};
