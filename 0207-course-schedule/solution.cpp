class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        int m=prerequisites.size();
        vector<vector<int>>adj(n);
        
        for(int i=0;i<m;i++)
        {   
            int u,v;
            u=prerequisites[i][1];
            v=prerequisites[i][0];
            adj[u].push_back(v);
        }
        
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int neighbour:adj[i])
            {
                indegree[neighbour]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int> topological_order;
        
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            topological_order.push_back(front);
            for(int neighbour:adj[front])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }

        }
        if(topological_order.size()==n)return true;
        return false;
        
    }
};
