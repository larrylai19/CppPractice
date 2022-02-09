class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN;
        int mn = INT_MAX;
        
        for (auto& p : prices) {
            mn = min(p, mn);
            profit = max(p - mn, profit);
        }
        
        return profit;
    }
};