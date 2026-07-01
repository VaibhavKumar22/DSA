class Solution {
    bool safe(vector<vector<char>>&b,int r,int c,int n){
        for(int i=0;i<9;i++){
            if(b[r][i]==(char)(n+'0')||b[i][c]==(char)(n+'0'))return false;
        }
            int nc=(c/3)*3;
            int nr=(r/3)*3;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(b[nr+i][nc+j]==(char)(n+'0'))return false;
                }
            }
        
            return true;
    }
    bool solve(vector<vector<char>>&b,int r,int c){
        if(r==9)return true;
        // if(r==8&& c==9)return true;
        if(c==9)
        return solve(b, r+1, 0);

        if(b[r][c]!='.'){
            return solve(b,r,c+1);
        }else{
            for(int i=1;i<=9;i++){
                if(safe(b,r,c,i)){
                    b[r][c]=(char)(i+'0');
                    if(solve(b,r,c+1))return true;
                    else {
                        b[r][c]='.';
                    }
                }
            }
        }
        return false;


    }
public:


    void solveSudoku(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        solve(board,0,0);
        
    }
};
