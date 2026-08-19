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
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);

        // Left subtree is unbalanced
        if (leftHeight == -1)
            return -1;

        int rightHeight = height(root->right);

        // Right subtree is unbalanced
        if (rightHeight == -1)
            return -1;

        // Current node is unbalanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};