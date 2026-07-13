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
        void dfs(TreeNode*root,int targetSum,int &n,int currentSum){
            if(!root){
                return;
            }
            currentSum+=root->val;
            if(!root->left&&!root->right&&currentSum==targetSum){
                n=1;
                return;
            }
            dfs(root->left,targetSum,n,currentSum);
            dfs(root->right,targetSum,n,currentSum);
            
        }
        
        bool hasPathSum(TreeNode* root, int targetSum) {
        int n=0;
        dfs(root,targetSum,n,0);
        if(n==1){
            return true;
        }
        
        return false;

    }
};