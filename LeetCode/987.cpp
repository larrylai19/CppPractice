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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int min_x = INT_MAX, max_x = INT_MIN;
        map<pair<int, int>, priority_queue<int, vector<int>, greater<int>>> m_;
        extract(root, 0, 0, m_, min_x, max_x);
        vector<vector<int>> v(max_x - min_x + 1);
        for(auto& m : m_)
            while(!m.second.empty())
                v[m.first.second - min_x].push_back(m.second.top()), m.second.pop();
        return v;
    }
private:
    void extract(TreeNode* root, int x, int y, map<pair<int, int>, priority_queue<int, vector<int>, greater<int>>>& m_, int& min_x, int& max_x)
    {
        if(!root) return;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        m_[{y, x}].push(root->val);
        extract(root->left, x - 1, y + 1, m_, min_x, max_x);
        extract(root->right, x + 1, y + 1, m_, min_x, max_x);
    }
};