class Solution {
    static bool cmp(const vector<int>& l, const vector<int>& r) { return l[1] < r[1]; }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0, n = intervals.size(), l = 0, r;
        sort(intervals.begin(), intervals.end(), cmp);
        while(l < n)
        {
            r = l + 1;
            while(r < n && intervals[l][1] > intervals[r][0]) ++r;
            count += r - l - 1;
            l = r;
        }
        return count;
    }
};