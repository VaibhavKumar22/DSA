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
private:
    unordered_map<int,int>mp;//store element index for inorder
    TreeNode* solve(int start,int end,int&idx,vector<int>preorder){
        if(start>end)return nullptr;
        int i=mp[preorder[idx]];
        TreeNode*root=new TreeNode(preorder[idx]);
        idx++;
        root->left=solve(start,i-1,idx,preorder);
        root->right=solve(i+1,end,idx,preorder);
        return root;



    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int start=0;
        int end=n-1;
        int idx=0;//idx of preorder
        return solve(0,end,idx,preorder);
    }
};