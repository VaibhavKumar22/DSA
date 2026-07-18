class Solution {
//     vector<vector<int>>dp;
//     int dfs(vector<vector<int>>& triangle,int row,int i){
//         if(triangle.size()==row)return 0;
//         if(dp[row][i]!=INT_MAX)return dp[row][i];
//         int case1=dfs(triangle,row+1,i);
//         int case2=dfs(triangle,row+1,i+1);
//         return dp[row][i]=min(case1,case2)+triangle[row][i];
// }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // int row=0;
        // int i=0;
        // dp.resize(triangle.size(),vector<int>(triangle.size(),INT_MAX));
        // return dfs(triangle,row,i);

        //without dp we can do it by modifying the origanal traiangle
        int n=triangle.size(); 
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int child1=triangle[i+1][j];
                int child2=triangle[i+1][j+1];
                triangle[i][j]+=min(child1,child2);
            }
        }    
        return triangle[0][0];   
    }


};