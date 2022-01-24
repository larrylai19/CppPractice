class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size(), fresh = 0, days = 0, size;
        int offset[] = {1, 0, -1, 0, 1};
        queue<pair<int, int>> q;
        for(int i = 0; i < height; ++i) for(int j = 0; j < width; ++j)
            if(grid[i][j] == 1) ++fresh; else if(grid[i][j] == 2) q.emplace(j, i);
        while((size = q.size()) && fresh && ++days) while(size--)
        {
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; ++i)
            {
                int dx = x + offset[i], dy = y + offset[i + 1];
                if(dx < 0 || dx >= width || dy < 0 || dy >= height || grid[dy][dx] != 1) continue;
                grid[dy][dx] = 2;
                --fresh;
                q.emplace(dx, dy);
            }
        }
        return fresh ? -1 : days;
    }
};