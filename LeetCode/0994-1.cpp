class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size(), fresh = 0, days = 0;
        int offset[] = {1, 0, -1, 0, 1};
        queue<pair<int, int>> _q;
        for(int i = 0; i < height; ++i) // y
            for(int j = 0; j < width; ++j) // x
                if(grid[i][j] == 1) ++fresh;
                else if(grid[i][j] == 2) _q.emplace(j, i);
        while(!_q.empty() && fresh)
        {
            int size = _q.size();
            while(size--)
            {
                int x = _q.front().first, y = _q.front().second;
                _q.pop();
                for(int i = 0; i < 4; ++i)
                {
                    int dx = x + offset[i], dy = y + offset[i + 1];
                    if(dx < 0 || dx >= width || dy < 0 || dy >= height || grid[dy][dx] != 1) continue;
                    --fresh;
                    grid[dy][dx] = 2;
                    _q.emplace(dx, dy);
                }
            }
            ++days;
        }
        return fresh ? -1 : days;
    }
};