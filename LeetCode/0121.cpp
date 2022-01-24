class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int cost = INT_MAX, profit{};
        for(auto price : prices) cost = min(price, cost), profit = max(price - cost, profit);
        return profit;
    }
};