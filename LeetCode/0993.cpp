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
    pair<int, int> get(TreeNode* root, int target, int depth, int father)
    {
        if(!root)
            return {father, -1};
        if(root->val == target)
            return {father, depth};
        auto left = get(root->left, target, ++depth, root->val);
        if(left.second != -1)
            return left;
        return get(root->right, target, depth, root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        auto xInfo = get(root, x, 0, root->val);
        auto yInfo = get(root, y, 0, root->val);
        if(xInfo.first != yInfo.first && xInfo.second == yInfo.second)
            return true;
        return false;
    }
};