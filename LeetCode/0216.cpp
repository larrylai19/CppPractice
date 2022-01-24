class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(k, n, 1, cur, res);
        return res;
    }
private:
    void dfs(int k, int n, int bound, vector<int>& cur, vector<vector<int>>& res)
    {
        if(!k) { if(!n) res.emplace_back(cur); return; }
        for(int i = bound; i <= 9; ++i)
        {
            cur.emplace_back(i);
            dfs(k - 1, n - i, i + 1, cur, res);
            cur.pop_back();
        }
    }
};