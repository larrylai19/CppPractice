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
    string largestNumber(vector<int>& nums)
    {
        string str;
        sort(nums.begin(), nums.end(), [](auto& l, auto&r) { return to_string(l) + to_string(r) > to_string(r) + to_string(l); });
        for(const auto& val : nums) str += to_string(val);
        return !nums.front() ? "0" : str;
    }
};