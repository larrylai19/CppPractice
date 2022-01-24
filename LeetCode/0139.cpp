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
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = s.length();
        vector<int> dp(n + 1);
        unordered_set<string> set(begin(wordDict), end(wordDict));
        s = " " + s;
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) for(int j = 0; j < i; ++j)
            if(dp[j] && set.count(s.substr(j + 1, i - j))) { dp[i] = 1; break; }
        return dp[n];
    }
};