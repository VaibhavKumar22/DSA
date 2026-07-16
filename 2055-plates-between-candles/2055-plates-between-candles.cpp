class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Prefix count of plates (*)
        vector<int> prefixPlate(n, 0);
        prefixPlate[0] = (s[0] == '*');

        for (int i = 1; i < n; i++) {
            prefixPlate[i] = prefixPlate[i - 1] + (s[i] == '*');
        }

        // Nearest candle on the left
        vector<int> leftCandle(n, -1);
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|')
                last = i;
            leftCandle[i] = last;
        }

        // Nearest candle on the right
        vector<int> rightCandle(n, -1);
        last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|')
                last = i;
            rightCandle[i] = last;
        }

        vector<int> ans;

        for (auto &e : queries) {
            int left = rightCandle[e[0]];
            int right = leftCandle[e[1]];

            if (left == -1 || right == -1 || left >= right) {
                ans.push_back(0);
            } else {
                ans.push_back(prefixPlate[right] - prefixPlate[left]);
            }
        }

        return ans;
    }
};