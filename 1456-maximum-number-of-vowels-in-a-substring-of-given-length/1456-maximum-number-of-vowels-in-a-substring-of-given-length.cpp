class Solution {
public:
    bool isvowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    int maxVowels(string s, int k) {
        int count=0;

        int i=0;
        while(k--){
            if(isvowel(s[i++]))count++;
        }
        int maxcount=count;
        int j=0;
        while(i<s.size()){
            if(isvowel(s[j++]))count--;
            if(isvowel(s[i++]))count++;
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};