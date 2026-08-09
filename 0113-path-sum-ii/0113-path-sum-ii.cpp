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
    void solve(TreeNode* root,vector<vector<int>>& ans,vector<int>& path,int target){
        if(root==NULL) return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && target==root->val){
            ans.push_back(path);
        }
        solve(root->left,ans,path,target-root->val);
        solve(root->right,ans,path,target-root->val);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root,ans,path,targetSum);
        return ans;
        
    }
};