class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        map<int,int> row,col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]++,col[j]++;
                }
            }
        }
        for(auto a:row){
            for(int i=0;i<m;i++)matrix[a.first][i]=0;
        }
        for(auto a:col){
            for(int i=0;i<n;i++)matrix[i][a.first]=0;
        }


    }
};
