class Solution {
private:
    bool safe(vector<vector<char>>& b, int r, int c, int n) {
        for (int i = 0; i < 9; i++) {
            if (b[r][i] == n + '0') return false;
            if (b[i][c] == n + '0') return false;
        }

        int nr = (r / 3) * 3;
        int nc = (c / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[nr + i][nc + j] == n + '0')
                    return false;
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                char ch = board[i][j];
                board[i][j] = '.';

                if (!safe(board, i, j, ch - '0'))
                    return false;

                board[i][j] = ch;
            }
        }

        return true;
    }
};
