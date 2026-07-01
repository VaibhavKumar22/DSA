class Solution {
private:
     bool safe(vector<string>&b,int r,int c){
        int n=b.size();
        for(int i=r-1;i>=0;i--){
            if(b[i][c]=='Q')return false;
        }
        for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++){
            if(b[i][j]=='Q')return false;
        }
        
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--){
            if(b[i][j]=='Q')return false;
        }
        return true;
    }
    void solve(vector<string>&b,vector<vector<string>>&ans,int n,int r){
        if(r==n){
            ans.push_back(b);
            return;
        }
        for(int i=0;i<n;i++){
            if(safe(b,r,i)){
                b[r][i]='Q';
                solve(b,ans,n,r+1);
                b[r][i]='.';
            }
        }
    }

public:
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>b(n,string(n,'.'));
        solve(b,ans,n,0);
        return ans.size();
        
    }
};