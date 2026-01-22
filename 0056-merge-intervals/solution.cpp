class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if(arr.empty()) return {};

        sort(arr.begin(), arr.end());  // 🔥 REQUIRED

        int n = arr.size();
        int j = 0;

        for(int i = 1; i < n; i++) {
            if(arr[j][1] >= arr[i][0]) {
                arr[j] = {min(arr[j][0], arr[i][0]), max(arr[j][1], arr[i][1])};
            } else {
                arr[++j] = arr[i];
            }
        }

        arr.resize(j + 1);
        return arr;
    }
};

