class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost1 = INT_MAX, cost2 = INT_MAX;
        int profit1 = 0, profit2 = 0;
        for(auto p : prices)
        {
            cost1 = min(p, cost1);
            profit1 = max(p - cost1, profit1);
            cost2 = min(p - profit1, cost2);
            profit2 = max(p - cost2, profit2);
            cout << cost1 << "  " << profit1 << endl << cost2 << "  " << profit2 << endl << endl;
        }
        return profit2;
    }
};