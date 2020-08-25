class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 1);
        unordered_set<int> set(days.begin(), days.end());
        for(int i = 1; i <= days.back(); ++i)
        {
            if(!set.count(i)) { dp[i] = dp[i - 1]; continue; }
            dp[i] = min(dp[max(0, i - 1)] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
        }
        return dp[days.back()];
    }
};