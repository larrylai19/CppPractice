class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        if(!height)
            return 0;
        int width = matrix[0].size(), Max = 0;
        auto dp = vector<vector<int>>(height + 1, vector<int>(width + 1, 0));
        for(int i = 1; i <= height; ++i)
            for(int j = 1; j <= width; ++j)
                if(matrix[i - 1][j - 1] == '1')
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1,    Max = max(Max, dp[i][j]);
        return Max * Max;
    }
};