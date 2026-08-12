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
    TreeNode* insertBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        else if(root->val>val){
            if(root->left==NULL){
                root->left=new TreeNode(val);
            }
            else insertBST(root->left,val);
        }
        else{
            if(root->right==NULL){
                root->right=new TreeNode(val);
            }
            else insertBST(root->right,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root=new TreeNode(pre[0]);
        for(int i=1;i<pre.size();i++){
              insertBST(root,pre[i]);
        }
        return root;
    }
};