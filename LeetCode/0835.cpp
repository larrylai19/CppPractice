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
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        int n = A.size(), cnt = 0;
        vector<pair<int, int>> posA, posB; // {x, y}
        map<pair<int, int>, int> m; // {x, y}, count
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
        {
            if(A[i][j]) posA.emplace_back(i, j);
            if(B[i][j]) posB.emplace_back(i, j);
        }
        for(auto& [xA, yA] : posA) for(auto& [xB, yB] : posB) ++m[{xB - xA, yB - yA}];
        for(auto& [__, val] : m) cnt = max(cnt, val);
        return cnt;
    }
};