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
    bool buddyStrings(string A, string B)
    {
        if (A.length() != B.length()) return false;
        if (A == B) return unordered_set<char>(A.begin(), A.end()).size() < A.length();
        vector<int> diff;
        for (int i = 0; i < A.length(); ++i) if (A[i] != B[i]) diff.emplace_back(i);
        return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
};