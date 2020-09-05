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
static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> t1, t2, v;
        getEle(t1, root1), getEle(t2, root2);
        int i = 0, j = 0, n1 = t1.size(), n2 = t2.size();
        v.reserve(n1 + n2);
        while(v.size() != n1 + n2)
        {
            if(i >= n1) v.emplace_back(t2[j++]);
            else if(j >= n2) v.emplace_back(t1[i++]);
            else v.emplace_back(t1[i] < t2[j] ? t1[i++] : t2[j++]);
        }
        return v;
    }
private:
    void getEle(vector<int>& v, TreeNode* root)
    {
        if(!root) return;
        getEle(v, root->left);
        v.emplace_back(root->val);
        getEle(v, root->right);
    }
};