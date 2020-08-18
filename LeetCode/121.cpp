class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        for(auto p : prices) cost = min(p, cost), profit = max(p - cost, profit);
        return profit;
    }
};