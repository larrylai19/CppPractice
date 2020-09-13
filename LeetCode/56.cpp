class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto& l, auto& r) { return l[0] < r[0]; });
        vector<vector<int>> res;
        for(auto& interval : intervals)
        {
            if(res.empty() || interval[0] > res.back()[1]) res.emplace_back(interval);
            else res.back()[1] = max(res.back()[1], interval[1]);
        }
        return res;
    }
};