class Solution {
    vector<int>parent,rank;
    int find(int n){
        if(parent[n]==n)return n;
        return parent[n]=find(parent[n]);
    }
    void Union(int x,int y){
        int px=find(x);
        int py=find(y);
        
        if(px==py)return;
        if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else if(rank[py]>rank[px]){
            parent[px]=py;
        }
        else {
            parent[px]=py;
            rank[py]++;
        }
        
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        parent.resize(isConnected.size());
        rank.resize(isConnected.size(),0);

        for(int i=0;i<isConnected.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<isConnected.size();i++){
            for(int j=i+1;j<isConnected.size();j++){
                if(isConnected[i][j]==1)Union(i,j);
            }
        }
        int provinces = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (parent[i] == i) {
                provinces++;
            }
        }
        
        return provinces;

        


        
    }
};