class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        int m=flights.size();
        for(int i=0;i<m;i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<vector<bool>>marked(n,vector<bool>(k+2,false));
        vector<vector<int>>dis(n,vector<int>(k+2,INT_MAX));
        dis[src][0]=0;
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        >pq;
        pq.push({0,src,0});
        while(!pq.empty()){
            auto [distance,cur,stops]=pq.top();
            pq.pop();
            if(cur==dst)return distance;
            if(stops>k)continue;
            if(marked[cur][stops])continue;
            marked[cur][stops]=true;
            for(auto [neigh,wt]:adj[cur]){
                if(stops + 1 <= k + 1){
                     int cur_dist = distance + wt;
                     if(dis[neigh][stops+1] > cur_dist){
                        dis[neigh][stops+1] = cur_dist;
                        pq.push({cur_dist, neigh, stops+1});
                        }
                }
            }}
        return -1;

    }
};
