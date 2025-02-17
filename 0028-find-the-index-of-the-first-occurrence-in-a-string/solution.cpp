class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int n1=needle.length();
        if(n==n1){
            if(haystack==needle){
                return 0;
            }
        }
        for(int i=0;i<=n-n1;i++){
            if(haystack[i]==needle[0]){
                int count=0;
                for(int j=0;j<n1;j++){
                    if(haystack[i+j]!=needle[j]){
                        count++;
                    }
                }
                if(count==0){
                    return i;
                }
            }
        }
        return -1;
    }
};
