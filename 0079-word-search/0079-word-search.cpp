class Solution {
public:
    bool ifExist(vector<vector<char>>&board,string word,int row,int col,int n,int m,int index){
        if(index==word.size())return true;
        if(row<0||col<0||row>=n||col>=m||board[row][col]!=word[index]||board[row][col]=='#')return false;
        char ch=board[row][col];
        board[row][col]='#';
        bool top=ifExist(board,word,row-1,col,n,m,index+1);
        bool right=ifExist(board,word,row,col+1,n,m,index+1);
        bool down=ifExist(board,word,row+1,col,n,m,index+1);
        bool left=ifExist(board,word,row,col-1,n,m,index+1);
        board[row][col]=ch;
        return top||right||down||left;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[index]){
                if(ifExist(board,word,i,j,n,m,index))return true;

                }
            }
        }
        return false;
       
    }
};