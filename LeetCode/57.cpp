class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        auto iter = intervals.begin();
        while(iter != intervals.end() && iter->at(0) < newInterval[0]) ++iter;
        intervals.insert(iter, newInterval);
        vector<vector<int>> res;
        for(auto& interval : intervals)
        {
            if(res.empty() || interval[0] > res.back()[1]) res.emplace_back(interval);
            else res.back()[1] = max(res.back()[1], interval[1]);
        }
        return res;
    }
};