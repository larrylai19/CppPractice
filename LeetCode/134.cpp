// fast IO
static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int total{}, curr{}, start{};
        for(int i{}; i < gas.size(); ++i)
        {
            curr += gas[i] - cost[i];
            if(curr < 0) start = i + 1, curr = 0;
            total += gas[i] - cost[i];
        }
        return total >= 0 ? start : -1;
    }
};