class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = INT_MIN;
        for (auto& v : accounts) mx = max(accumulate(v.begin(), v.end(), 0), mx);
        return mx;
    }
};