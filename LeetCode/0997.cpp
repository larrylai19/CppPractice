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
    int findJudge(int N, vector<vector<int>>& trust) {
        auto trusts = vector<vector<int>>(N + 1, vector<int>(2));
        for(auto i : trust)
            ++trusts[i[0]][0], ++trusts[i[1]][1];
        for(int i = 1; i <= N; ++i)
            if(!trusts[i][0] && trusts[i][1] == N - 1)
                return i;
        return -1;
    }
};