class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int end) {
        vector <pair<int, double>> g[n];
        int i=0;
        for(auto have : edges){
            int u = have[0];
            int v = have[1];
            double w = succProb[i++];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        i=0;
        vector<double>dist(n,0);
        priority_queue<pair<double,int>>q;
        dist[src]=1.0;
        q.push({dist[src],src});

        while(!q.empty()){
            auto [dis,node]=q.top();
            q.pop();
            if(dis<dist[node])continue;
            for(auto [nig,wt]:g[node]){
                if(dist[nig]<dis*wt){
                    dist[nig]=dis*wt;
                    q.push({dist[nig],nig});
                }
            }
        }
        return dist[end];
    }
};