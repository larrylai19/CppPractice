// fast IO
static auto __ = []() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0; 
}();
class StockSpanner {
public:
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        if(i == 0 || price < prices.back())
            dp.push_back(1);
        else
        {
            int j = i - 1;
            while(j >= 0 && price >= prices[j])
                j -= dp[j];
            dp.push_back(i - j);
        }
        ++i;
        prices.push_back(price);
        return dp.back();
    }
private:
    vector<int> dp;
    vector<int> prices;
    int i;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */