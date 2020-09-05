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
        return merge(t1, t2);
    }

private:
    void getEle(vector<int>& v, TreeNode* root)
    {
        if(!root) return;
        getEle(v, root->left);
        v.emplace_back(root->val);
        getEle(v, root->right);
    }
    
    vector<int> merge(vector<int>& v1, vector<int>& v2)
    {
        int n1 = v1.size(), n2 = v2.size();
        vector<int> v(n1 + n2);
        int i = 0, i1 = 0, i2 = 0;
        while(i1 < n1 || i2 < n2)
        {
            if(i1 >= n1) v[i++] = v2[i2++];
            else if(i2 >= n2) v[i++] = v1[i1++];
            else v[i++] = v1[i1] < v2[i2] ? v1[i1++] : v2[i2++];
        }
        return v;
    }
};