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
    int dfs(TreeNode*root,int &maxi){
        if(!root)return 0;

        int left=max(0,dfs(root->left,maxi));
        int right=max(0,dfs(root->right,maxi));
        maxi=max(maxi,root->val+left+right);
        return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        dfs(root,maxi);
        return maxi;
        
    }
};