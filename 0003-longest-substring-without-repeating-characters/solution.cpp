class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_map<char,int> freq;
        int i=0,j=0,n=s.size();
        while (i < n) {
            freq[s[i]]++;

            while (freq[s[i]] > 1) {
                freq[s[j]]--;
                j++;
            }

            ans = max(ans, i - j + 1);
            i++;
        }

        return ans;
        
        
    }
};
