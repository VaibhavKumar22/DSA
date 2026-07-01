class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word = "";
};

class Solution {
public:
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c])
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (node->children.find(c) == node->children.end()) return;

        node = node->children[c];
        if (node->word != "") {
            result.push_back(node->word);
            node->word = "";  // avoid duplicates
        }

        board[i][j] = '#';
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d], nj = j + dy[d];
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size() && board[ni][nj] != '#') {
                dfs(board, ni, nj, node, result);
            }
        }

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (const string& word : words) {
            insert(root, word);
        }

        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};
