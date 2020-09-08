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
    bool hasPathSum(TreeNode* root, int sum, int curSum = 0) // add curSum
    {
        if(!root) return false;
        curSum += root->val;
        if(!root->left && !root->right && curSum == sum) return true;
        return hasPathSum(root->left, sum, curSum) || hasPathSum(root->right, sum, curSum);
    }
};