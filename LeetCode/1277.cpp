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
    int countSquares(vector<vector<int>>& matrix) {
        int height = matrix.size(), width = matrix[0].size(), count = 0;
        for(int i = 0; i < height; ++i)
            for(int j = 0; j < width; ++j)
            {
                if(i != 0 && j != 0 && matrix[i][j] == 1)
                    matrix[i][j] += min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
                count += matrix[i][j];
            }
        return count;
    }
};