class Solution {
public:
    void mark(vector<vector<char>>& grid, int i, int j, int height, int width)
    {
        if(i < 0 || j < 0 || i >= height || j >= width || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        mark(grid, i, j + 1, height, width);
        mark(grid, i, j - 1, height, width);
        mark(grid, i + 1, j, height, width);
        mark(grid, i - 1, j, height, width); 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        if(!height)    
            return 0;
        int width = grid[0].size(), numberOfRegions = 0;
        for(int i = 0; i < height; ++i)
            for(int j = 0; j < width; ++j)
                if(grid[i][j] == '1')
                    mark(grid, i, j, height, width),    ++numberOfRegions;
        return numberOfRegions;
    }
};