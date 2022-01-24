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
        
    }
    
    int next(int price) {
        int span = 1;
        while(!s.empty() && s.top().first <= price)
            span += s.top().second, s.pop();
        s.emplace(price, span);
        return span;
    }
private:
    // {price, span}
    stack<pair<int, int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */