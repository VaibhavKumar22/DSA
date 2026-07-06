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
    unordered_map<int,int>mp;
    TreeNode* solve(int start,int end,int&idx,vector<int>&postorder){
        if(start>end)return nullptr;
        int i=mp[postorder[idx]];
        TreeNode* root=new TreeNode(postorder[idx]);
        idx--;
        root->right=solve(i+1,end,idx,postorder);
        root->left=solve(start,i-1,idx,postorder);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int start=0;
        int end=n-1;
        int idx=n-1;
        return solve(start,end,idx,postorder);
        
    }
};