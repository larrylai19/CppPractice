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
    int maxSubarraySumCircular(vector<int>& A) {
        int mx = INT_MIN, mn = INT_MAX, currMax = 0, currMin = 0, sum = 0;
        for(auto i : A)
        {
            currMax = max(currMax + i, i);
            currMin = min(currMin + i, i);
            mx = max(currMax, mx);
            mn = min(currMin, mn);
            sum += i;
        }
        return sum == mn ? mx : max(sum - mn, mx);
    }
};