class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<int>indegree(V,0);
        int count=0;
        vector<vector<int>>adj(V);
        for(auto e:prerequisites){
            int u=e[1];
            int v=e[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        if(q.empty())return false;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int nig:adj[node]){
                indegree[nig]--;
                if(indegree[nig]==0)q.push(nig);
            }
        }
        return (count==V);


        
        
    }
};