#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> xor_sum(n), parent(n), tin(n), tout(n);
        int timer = 0;
        dfs(0, -1, adj, nums, xor_sum, parent, tin, tout, timer);
        int res = INT_MAX;

        // For each pair of edges, select the child (deeper node)
        for (int i = 0; i < edges.size(); ++i) {
            int u1 = edges[i][0], v1 = edges[i][1];
            if (parent[u1] == v1)
                swap(u1, v1);
            // Now u1 is parent, v1 is child (so cut is between u1 and v1, v1 forms the subtree)
            for (int j = i + 1; j < edges.size(); ++j) {
                int u2 = edges[j][0], v2 = edges[j][1];
                if (parent[u2] == v2)
                    swap(u2, v2);
                // Now u2 is parent, v2 is child
                int a = v1, b = v2;
                int x1, x2, x3;
                if (is_ancestor(a, b, tin, tout)) {
                    // b in a's subtree
                    x1 = xor_sum[b];
                    x2 = xor_sum[a] ^ xor_sum[b];
                    x3 = xor_sum[0] ^ xor_sum[a];
                } else if (is_ancestor(b, a, tin, tout)) {
                    // a in b's subtree
                    x1 = xor_sum[a];
                    x2 = xor_sum[b] ^ xor_sum[a];
                    x3 = xor_sum[0] ^ xor_sum[b];
                } else {
                    // disjoint subtrees
                    x1 = xor_sum[a];
                    x2 = xor_sum[b];
                    x3 = xor_sum[0] ^ xor_sum[a] ^ xor_sum[b];
                }
                int mx = max({x1, x2, x3});
                int mn = min({x1, x2, x3});
                res = min(res, mx - mn);
            }
        }
        return res;
    }

    void dfs(int u, int p, const vector<vector<int>>& adj, const vector<int>& nums,
             vector<int>& xor_sum, vector<int>& parent, vector<int>& tin, vector<int>& tout, int& timer) {
        tin[u] = timer++;
        xor_sum[u] = nums[u];
        parent[u] = p;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, adj, nums, xor_sum, parent, tin, tout, timer);
            xor_sum[u] ^= xor_sum[v];
        }
        tout[u] = timer++;
    }
    bool is_ancestor(int u, int v, const vector<int>& tin, const vector<int>& tout) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }
};

