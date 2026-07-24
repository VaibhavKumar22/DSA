class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> freq;

        for (auto &day : responses) {
            unordered_set<string> seen(day.begin(), day.end());
            for (auto &s : seen)
                freq[s]++;
        }

        string ans = "";
        int mx = 0;

        for (auto &[s, cnt] : freq) {
            if (cnt > mx || (cnt == mx && (ans.empty() || s < ans))) {
                mx = cnt;
                ans = s;
            }
        }

        return ans;
    }
};