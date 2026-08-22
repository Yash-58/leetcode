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
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*, TreeNode*> parent;
        
        TreeNode* startNode = nullptr;
        
        // Create parent mapping
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->val == start)
                startNode = node;
            
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        
        // BFS infection
        unordered_set<TreeNode*> visited;
        q.push(startNode);
        visited.insert(startNode);
        
        int time = -1;
        
        while (!q.empty()) {
            int size = q.size();
            time++;
            
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                
                // Left child
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                
                // Right child
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                
                // Parent
                if (parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }
        
        return time;
    }
};