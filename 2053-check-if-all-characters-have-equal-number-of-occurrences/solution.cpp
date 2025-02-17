class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int a=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[0]){
               a++;
               s[i]='0';
            }
        }

        for(int i=1;i<s.length();i++){
            if(s[i]!='0'){
            int count=1;
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]){
                    count++;
                    s[j]='0';
                }
            }
            if(count!=a){
                return false;
            }
        }}

       return true; 
    }
};
