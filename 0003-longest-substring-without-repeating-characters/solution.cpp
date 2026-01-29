class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int max1=0;
        unordered_map<char,int> a;
        for(int i=0;i<s.size();i++){
            int count=1;
            a[s[i]]=1;
            int j=i+1;
            while(j<s.size()&&!a[s[j]]){
                count++;
                a[s[j++]]=1;
                
            }
            max1=max(count,max1);
            a.clear();
        }
        return max1;

        
    }
};
