class Solution {
public:
    struct TrieNode {
        map<string, TrieNode*> children;
        string serial;
        bool is_deleted = false;
    };

    TrieNode* root = new TrieNode();
    unordered_map<string, int> freq;

    void insert(vector<string>& path) {
        TrieNode* node = root;
        for (string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new TrieNode();
            }
            node = node->children[folder];
        }
    }

    string serialize(TrieNode* node) {
        if (node->children.empty()) return "";

        string key = "";
        for (auto& [name, child] : node->children) {
            key += "(" + name + serialize(child) + ")";
        }

        node->serial = key;
        freq[key]++;
        return key;
    }

    void mark_duplicates(TrieNode* node) {
        for (auto& [name, child] : node->children) {
            mark_duplicates(child);
        }
        if (!node->serial.empty() && freq[node->serial] > 1) {
            node->is_deleted = true;
        }
    }

    void collect(TrieNode* node, vector<string>& path, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (!child->is_deleted) {
                path.push_back(name);
                res.push_back(path);
                collect(child, path, res);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path : paths) {
            insert(path);
        }

        serialize(root);
        mark_duplicates(root);

        vector<vector<string>> result;
        vector<string> curr;
        collect(root, curr, result);
        return result;
    }
};

