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
    bool dfs(TreeNode*root,int&k,unordered_map<int,int>&mp){
        if(!root)return false;
        if(mp[root->val])return true;
        mp[k-root->val]++;
        return dfs(root->left,k,mp) || dfs(root->right,k,mp);
        
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        return dfs(root,k,mp);
        
        
    }
};