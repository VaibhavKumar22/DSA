class Solution {
public:
    bool isPalindrome(string s) {
        int i=-1;
        int j=i+1;
        while(j<s.size()){
            if(isalnum(s[j])){
                s[++i]=tolower(s[j]);
            }
            j++;
        }
        j=i;
        i=0;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
        
        
        
    }
};
