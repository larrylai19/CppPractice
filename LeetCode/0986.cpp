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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0, s, e;
        vector<vector<int>> res;
        while(i < A.size() && j < B.size())
        {
            s = max(A[i][0], B[j][0]);
            e = min(A[i][1], B[j][1]);
            if(s <= e)
                res.emplace_back(vector<int>{s, e});
            A[i][1] > B[j][1] ? ++j : ++i;
        }
        return res;
    }
};