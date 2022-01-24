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
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxL = 0;
        vector<int> v(128, -1);
        for(int i = 0, j = 0; j < n; ++j)
        {
            i = max(i, v[s[j]] + 1);
            maxL = max(maxL, j - i + 1);
            v[s[j]] = j;
        }
        return maxL;
    }
};