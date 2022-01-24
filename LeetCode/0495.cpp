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
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int ret{}, n = timeSeries.size();
        for(int i{}; i < n - 1; ++i) ret += min(timeSeries[i + 1] - timeSeries[i], duration);
        return n ? ret + duration : 0;
    }
};