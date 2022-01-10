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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        dfs(root, 0);
        return ret;
    }
    
private:
    vector<vector<int>> ret;
    
    void dfs(TreeNode* n, int deep) {
        if (!n) return;
        
        if (ret.size() <= deep) ret.resize(deep + 1);
        
        if (deep % 2) ret[deep].insert(ret[deep].begin(), n->val);
        else ret[deep].push_back(n->val);
        
        dfs(n->left, deep + 1);
        dfs(n->right, deep + 1);
    }
};