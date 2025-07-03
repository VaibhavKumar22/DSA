/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        vector<vector<int>>result;
        void dfs(TreeNode*root,int targetSum,vector<int>&path,int currentSum){
            if(!root){
                return;
            }
            path.push_back(root->val);
            currentSum+=root->val;
            if(!root->left&&!root->right&&currentSum==targetSum){
                result.push_back(path);
            }
            dfs(root->left,targetSum,path,currentSum);
            dfs(root->right,targetSum,path,currentSum);
            path.pop_back();
        }
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<int>path;
            dfs(root,targetSum,path,0);
            return result;
        
    }
};
