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
// fast IO
static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        ++_m[0];
        traverse(root, 0, sum, count);
        return count;
    }
private:
    unordered_map<int, int> _m;
    
    void traverse(TreeNode* root, int sum, int target, int& count)
    {
        if(!root) return;
        sum += root->val;
        count += _m[sum - target]; // sum - (sum - target) = target
        ++_m[sum];
        traverse(root->left, sum, target, count);
        traverse(root->right, sum, target, count);
        --_m[sum];
    }
};