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
    vector<int>a;
    void inorder(TreeNode*root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        if(a.size()==1){
            return -1;
        }
        return a[1];


        
    }
};
