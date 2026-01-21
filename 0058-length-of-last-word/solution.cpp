class Solution {
public:
    int lengthOfLastWord(string s) { 
        int j=s.size()-1;
        if(s[j]==' '){
            while(s[j]==' ')j--;
        }
        int count=0;
        while(s[j]!=' '){
            count++;
            if(j==0)break;
            j--;

        }
        return count;
        
    }
};
