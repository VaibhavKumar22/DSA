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
    void insert(TreeNode*root,int &key){
        if(root->val>key){
            if(root->left==nullptr){
                root->left=new TreeNode(key);
                return;
            }
            else{
                insert(root->left,key);
            }
        }
        else {
            if(root->right==nullptr){
                root->right=new TreeNode(key);
                return;
            }
            else{
                insert(root->right,key);
            }
        }

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(root,preorder[i]);
        }
        return root;

        
    }
};