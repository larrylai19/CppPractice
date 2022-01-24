class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> v;
        if(N == 1) v.emplace_back(0);
        for(int i = 1; i <= 9; ++i) dfs(N - 1, K, i, v);
        return v;
    }
private:
    void dfs(int N, int K, int cur, vector<int>& v)
    {
        if(!N) { v.emplace_back(cur); return; }
        int l = cur % 10;
        if(l + K <= 9) dfs(N - 1, K, cur * 10 + l + K, v);
        if(l - K >= 0 && K) dfs(N - 1, K, cur * 10 + l - K, v);
    }
};