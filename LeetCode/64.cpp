class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size();
        unordered_map<int, unordered_map<int, int>> dp;
        dp[0][0] = grid[0][0];
        for(int i = 0; i < height; ++i)
            for(int j = 0; j < width; ++j)
            {
                if(!i && !j)
                    continue;
                int min = INT_MAX;
                if(j - 1 >= 0)
                    min = dp[i][j - 1] < min ? dp[i][j - 1] : min;
                if(i - 1 >= 0)
                    min = dp[i - 1][j] < min ? dp[i - 1][j] : min;
                dp[i][j] = min + grid[i][j];
            }
        return dp[height - 1][width - 1];
    }
};