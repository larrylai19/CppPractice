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
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> v;
        map<int, int> m;
        auto iter = m.begin();
        for(int i = 0; i < intervals.size(); ++i) m[intervals[i][0]] = i;
        for(auto& interval : intervals)
            v.emplace_back((iter = m.lower_bound(interval[1])) != m.end() ? iter->second : -1);
        return v;
    }
};