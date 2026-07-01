class Solution {
    bool valid(int i,int j,int n,int m){
        return (i>=0&&j>=0&&i<n&&j<m);
    }
    bool solve(int i,int j,string word,vector<vector<char>>&b,int idx,int n,int m){
        if(idx==word.size())return true;
        if(!valid(i,j,n,m))return false;
        if(b[i][j]!=word[idx]||b[i][j]=='*')return false;
        char ch=b[i][j];
        b[i][j]='*';
        bool right=solve(i,j+1,word,b,idx+1,n,m);
        bool left=solve(i,j-1,word,b,idx+1,n,m);
        bool up=solve(i+1,j,word,b,idx+1,n,m);
        bool down=solve(i-1,j,word,b,idx+1,n,m);
        b[i][j]=ch;
        return right||left||up||down;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();

        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,word,board,0,n,m))return true;
                }
            }
        }
        return false; 
        
    }
};

 
