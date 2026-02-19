class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j, int original, int color) {
        
        int rows = image.size();
        int cols = image[0].size();
        if(i < 0 || i >= rows || j < 0 || j >= cols)
            return;
        if(image[i][j] != original)
            return;
        image[i][j] = color;
        dfs(image, i+1, j, original, color);
        dfs(image, i-1, j, original, color);
        dfs(image, i, j+1, original, color);
        dfs(image, i, j-1, original, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {   
        int original = image[sr][sc];
        if(original == color)
            return image;
        dfs(image, sr, sc, original, color);
        
        return image;
    }
};

