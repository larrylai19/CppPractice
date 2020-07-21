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
    // 找出以 root 當終點的最大和
    int maxPath(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(maxPath(root->left) + root->val, max(maxPath(root->right) + root->val, 0));
    }
    // 找出任意起點任意終點的最大和
    int maxPathSum(TreeNode* root) {
       if(!root) 
           return INT_MIN;
        return max(maxPathSum(root->left), max(maxPath(root->left) + root->val + maxPath(root->right), maxPathSum(root->right)));
    }
};