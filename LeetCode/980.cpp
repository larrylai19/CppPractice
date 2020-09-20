class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int x, y, target{};
        for(int i{}; i < grid.size(); ++i) for(int j{}; j < grid[0].size(); ++j)
        {
            if(!grid[i][j]) ++target;
            else if(grid[i][j] == 1) x = j, y = i;
        }
        return dfs(grid, x, y, 0, target);
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y, int n, int target)
    {
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] == -1) return 0;
        if(grid[y][x] == 2) return n == target;
        if(!grid[y][x]) ++n;
        grid[y][x] = -1;
        int tmp = dfs(grid, x + 1, y, n, target) + dfs(grid, x - 1, y, n, target) + dfs(grid, x, y + 1, n, target) + dfs(grid, x, y - 1, n, target);
        grid[y][x] = 0;
        return tmp;
    }
};