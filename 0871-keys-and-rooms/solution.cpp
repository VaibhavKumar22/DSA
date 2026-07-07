class Solution {
private:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;
        for(int nig:adj[node]){
            if(!visited[nig]){
                dfs(nig,adj,visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n=rooms.size();
        vector<bool>visited(n,false);
        dfs(0,rooms,visited);
        for(bool ans:visited){
            if(ans==false)return false;
        }
        return true;

    }
};
