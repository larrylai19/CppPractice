// ref: https://www.youtube.com/watch?v=ucugbKwjtRs&ab_channel=HuaHua

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        _rows = vector<vector<bool>>(9, vector<bool>(10));
        _cols = vector<vector<bool>>(9, vector<bool>(10));
        _boxes = vector<vector<bool>>(9, vector<bool>(10));
        
        init(board);
        fill(board, 0, 0);
    }
    
private:
    int getBoxKey(int x, int y) {
        // 一排三個 box，所以 y 除完後乘以 3
        return (y / 3) * 3 + x / 3;
    }
    
    void init(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                
                int n = board[i][j] - '0';
                _rows[i][n] = true;
                _cols[j][n] = true;
                _boxes[getBoxKey(j, i)][n] = true;
            }
        }
    }
    
    bool fill(vector<vector<char>>& board, int x, int y) {
        if (y == 9) return true;
        
        int nx = (x + 1) % 9;
        int ny = !nx ? y + 1 : y;
        
        if (board[y][x] != '.') return fill(board, nx, ny);
        
        for (int i = 1; i <= 9; ++i) {
            if (_rows[y][i] || _cols[x][i] || _boxes[getBoxKey(x, y)][i]) continue;
            
            _rows[y][i] = true;
            _cols[x][i] = true;
            _boxes[getBoxKey(x, y)][i] = true;
            board[y][x] = '0' + i;
            
            if (fill(board, nx, ny)) return true;
            
            _rows[y][i] = false;
            _cols[x][i] = false;
            _boxes[getBoxKey(x, y)][i] = false;
            board[y][x] = '.';
        }
        
        return false;
    }
    
private:
    vector<vector<bool>> _rows;
    vector<vector<bool>> _cols;
    vector<vector<bool>> _boxes;
};