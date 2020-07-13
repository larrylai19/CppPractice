class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size();
        vector<vector<int>> dp(height + 1, vector<int>(width + 1, INT_MAX));
        dp[0][1] = 0;
        for(int i = 1; i <= height; ++i)
            for(int j = 1; j <= width; ++j)
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i - 1][j - 1];
        return dp[height][width];
    }
};