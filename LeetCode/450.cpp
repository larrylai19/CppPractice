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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val < key) root->right = deleteNode(root->right, key);
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else // root->val == key
        {
            if(!root->left || !root->right)
            {
                auto newRoot = root->right ? root->right : root->left;
                delete root;
                return newRoot;
            }
            else
            {
                auto min = root->right;
                while(min->left) min = min->left;
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
        }
        return root;
    }
};