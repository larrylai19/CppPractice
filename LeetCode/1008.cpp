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
    int pos = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int max = INT_MAX) {
        if(pos == preorder.size() || preorder[pos] > max)   
            return nullptr;
        return new TreeNode(preorder[pos], bstFromPreorder(preorder, preorder[pos++]), bstFromPreorder(preorder, max));
    }
};