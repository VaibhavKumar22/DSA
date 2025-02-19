class Solution {
public:
    int maxDifference(string s) {
        int odd=0;
        int even=100;
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
            int count=1;
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]){
                    count++;
                    s[j]='0';
                }
            }
            if(count%2==0){
                if(even>count){
                    even=count;
                }
                
            }
            else{
                if(odd<count){
                    odd=count;
                }
            }
            }
        }
            return odd-even;
        
    }
};
