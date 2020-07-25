class Solution {
public:
    void fill(vector<vector<int>>& image, int i, int j, int oldColor, int newColor, int height, int width)
    {
        if(i < 0 || j < 0 || i >= height || j >= width || image[i][j] != oldColor)
            return;
        image[i][j] = newColor;
        fill(image, i + 1, j, oldColor, newColor, height, width);
        fill(image, i - 1, j, oldColor, newColor, height, width);
        fill(image, i, j + 1, oldColor, newColor, height, width);
        fill(image, i, j - 1, oldColor, newColor, height, width);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        int height = image.size(), width = image[0].size();
        fill(image, sr, sc, image[sr][sc], newColor, height, width);
        return image;
    }
};