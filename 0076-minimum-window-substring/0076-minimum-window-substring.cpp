class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        for (char c : t)
            mp[c]++;

        int count = t.size();
        int i = 0;

        int start = 0;
        int minLen = INT_MAX;

        for (int j = 0; j < s.size(); j++) {

            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;

                if (mp[s[j]] >= 0)
                    count--;
            }

            while (count == 0) {

                // Store answer
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;

                    if (mp[s[i]] > 0)
                        count++;
                }

                i++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};