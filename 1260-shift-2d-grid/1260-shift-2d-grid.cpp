class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int c=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>arr(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[c++]=grid[i][j];
            }
        }
        k %= n*m;
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());

        c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = arr[c++];
            }
        }

        return grid;

        
        
        
    }
};