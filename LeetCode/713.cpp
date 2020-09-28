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
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if(k <= 1) return 0;
        int l = 0, prod = 1, ret = 0, n = nums.size();
        for(int r = 0; r < n; ++r)
        {
            prod *= nums[r];
            while(prod >= k) prod /= nums[l++];
            ret += r - l + 1;
        }
        return ret;
    }
};