class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        _rows = vector<vector<bool>>(9, vector<bool>(10));
        _cols = vector<vector<bool>>(9, vector<bool>(10));
        _boxes = vector<vector<bool>>(9, vector<bool>(10));
        
        return isValid(board);
    }
    
private:
    int getBoxKey(int x, int y) { return (y / 3) * 3 + x / 3; }
    
    bool isValid(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                
                int n = board[i][j] - '0';
                if (_rows[i][n] || _cols[j][n] || _boxes[getBoxKey(j, i)][n]) return false;
                _rows[i][n] = true;
                _cols[j][n] = true;
                _boxes[getBoxKey(j, i)][n] = true;
            }
        }
        
        return true;
    }
    
private:
    vector<vector<bool>> _rows;
    vector<vector<bool>> _cols;
    vector<vector<bool>> _boxes;
};