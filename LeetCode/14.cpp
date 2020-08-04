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
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        int n = strs.size(), N = strs[0].size();
        for(int i = 0; i < N; ++i)
            for(int j = 1; j < n; ++j)
                if(strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
        return strs[0];
    }
};