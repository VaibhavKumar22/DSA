class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>, int> mp;
        int ans = 0;

        for (auto &p : coordinates) {
            int x = p[0];
            int y = p[1];

            // Check all possible splits of k
            for (int dx = 0; dx <= k; dx++) {
                int dy = k - dx;

                int px = x ^ dx;
                int py = y ^ dy;

                if (mp.count({px, py}))
                    ans += mp[{px, py}];
            }

            mp[{x, y}]++;
        }

        return ans;
        
    }
};
