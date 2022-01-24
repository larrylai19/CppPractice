// fast IO
static auto __ = []() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), m = INT_MIN, l = 0, r = n - 1, L, W;
        while(l < r)
        {
            L = min(height[l], height[r]);
            W = r - l;
            m = max(m, L * W);
            height[l] > height[r] ? --r : ++l;
        }
        return m;
    }
};