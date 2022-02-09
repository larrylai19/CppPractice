// ref: https://www.cnblogs.com/grandyang/p/4362675.html

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), n = matrix.size();
        int x = 0, y = 0, idx = 0, tot = m * n;
        vector<int> ret;
        
        while (ret.size() < tot) {
            ret.push_back(matrix[y][x]);
            matrix[y][x] = INF;
            
            int nx = x + dir[idx][0], ny = y + dir[idx][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[ny][nx] == INF) {
                idx = (idx + 1) % 4;
                nx = x + dir[idx][0], ny = y + dir[idx][1];
            }
            x = nx, y = ny;
        }
        
        return ret;
    }
    
private:
    const int INF = 101;
    const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
};