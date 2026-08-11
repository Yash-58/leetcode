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
    void helper(TreeNode* root,TreeNode* &prev,bool &flag){
        if(root==NULL) return;

        helper(root->left,prev,flag);
        if(prev!=NULL){
            if(root->val<=prev->val){
            flag=false;
            return;
            }
        }
        prev =root;
        helper(root->right,prev,flag);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        bool flag=true;
         helper(root,prev,flag);
         return flag;
        
    }
};