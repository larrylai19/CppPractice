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
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), target = n - 1, count = 0;
        vector<int> zeroes(n);
        for(int i = 0; i < n; ++i) for(int j = n - 1; j >= 0 && !grid[i][j]; ++zeroes[i], --j);
        for(int i = 0; i < n; ++i, --target)
        {
            int j = i;
            while(j < n && target > zeroes[j]) ++j;
            if(j == n) return -1;
            zeroes.insert(zeroes.begin() + i, zeroes[j]);
            zeroes.erase(zeroes.begin() + j + 1);
            count += j - i;
        }
        return count;
    }
};