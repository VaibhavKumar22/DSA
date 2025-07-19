class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());  // Step 1: sort lexicographically
        
        vector<string> result;
        for (const string& path : folder) {
            // Step 2: check if path is a subfolder of last result
            if (result.empty() || path.find(result.back() + "/") != 0) {
                result.push_back(path);
            }
        }
        return result;
    }
};

