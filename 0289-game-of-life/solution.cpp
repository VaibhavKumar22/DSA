class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> copy = board;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                int live = 0;

                if (i-1 >= 0 && j-1 >= 0 && copy[i-1][j-1] == 1) live++;
                if (i-1 >= 0 && copy[i-1][j] == 1) live++;
                if (i-1 >= 0 && j+1 < col && copy[i-1][j+1] == 1) live++;
                if (j-1 >= 0 && copy[i][j-1] == 1) live++;
                if (j+1 < col && copy[i][j+1] == 1) live++;
                if (i+1 < row && j-1 >= 0 && copy[i+1][j-1] == 1) live++;
                if (i+1 < row && copy[i+1][j] == 1) live++;
                if (i+1 < row && j+1 < col && copy[i+1][j+1] == 1) live++;

                if(copy[i][j] == 1){
                    if(live < 2 || live > 3) board[i][j] = 0;
                }
                else{
                    if(live == 3) board[i][j] = 1;
                }
            }
        }
    }
};

