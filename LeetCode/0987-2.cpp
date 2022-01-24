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
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        int min_x = INT_MAX, max_x = INT_MIN;
        map<pair<int, int>, priority_queue<int, vector<int>, greater<int>>> _m;
        
        function<void(TreeNode*, int, int)> traversal = [&](TreeNode* r, int x, int y)
        {
            if (!r) return;
            min_x = min(x, min_x);
            max_x = max(x, max_x);
            _m[{y, x}].push(r->val);
            traversal(r->left, x - 1, y + 1);
            traversal(r->right, x + 1, y + 1);
        };
        
        traversal(root, 0, 0);
        vector<vector<int>> v(max_x - min_x + 1);
        for (auto& [pos, pq] : _m) while (!pq.empty()) v[pos.second - min_x].emplace_back(pq.top()), pq.pop();
        return v;
    }
};