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
    
    void traverse(TreeNode* root, int currSum, int target, int& count)
    {
        if(!root) return;
        currSum += root->val;
        count += _m[currSum - target]; // currSum - (currSum - target) = target
        ++_m[currSum];
        traverse(root->left, currSum, target, count);
        traverse(root->right, currSum, target, count);
        --_m[currSum];
    }
};