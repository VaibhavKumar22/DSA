class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //adj list        
        vector <pair<int, int>> adj[n+1];
        for(auto have : times){
            int u = have[0];
            int v = have[1];
            int w = have[2];
            adj[u].push_back({v, w});
        }
        //dist from source to all possible reachable node 
        vector<int> dist(n + 1, 1e8);
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){

            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto &[adjNode, wt] : adj[node]){

                if(dist[adjNode] > dis + wt){

                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){
            ans = max(ans, dist[i]);
        }

        return ans!=1e8?ans:-1;
    }
};