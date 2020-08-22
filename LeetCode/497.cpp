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
    Solution(vector<vector<int>>& rects) : _rects(rects) {
        for(int i = 0, count = 0; i < rects.size(); ++i)
            count += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1), dots.emplace_back(count);
        srand(time(nullptr));
    }
    
    vector<int> pick() {
        int pos = lower_bound(dots.begin(), dots.end(), rand() % dots.back() + 1) - dots.begin();
        int length = _rects[pos][2] - _rects[pos][0] + 1, width = _rects[pos][3] - _rects[pos][1] + 1;
        return {_rects[pos][0] + rand() % length, _rects[pos][1] + rand() % width};
    }
private:
    vector<vector<int>> _rects;
    vector<int> dots;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */