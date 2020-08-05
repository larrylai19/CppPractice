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
    int getWinner(vector<int>& arr, int k) {
        int currMax = arr[0], count = 0, n = arr.size();
        for(int i = 1; i < n; ++i)
        {
            arr[i] > currMax ? currMax = arr[i], count = 1 : ++count;
            if(count == k)
                return currMax;
        }
        return currMax;
    }
};