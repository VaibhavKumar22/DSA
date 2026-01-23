class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &x : words) {
            int i = 0, j = x.size() - 1;
            bool ok = true;

            while (i < j) {
                if (x[i++] != x[j--]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return x;
        }
        return "";
    }
};

