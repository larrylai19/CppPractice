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
    vector<int> majorityElement(vector<int>& nums)
    {
        int bound = nums.size() / 3;
        vector<int> ret;
        unordered_map<int, int> cnt;
        for(auto num : nums) ++cnt[num];
        for(auto& [num, times] : cnt) if(times > bound) ret.emplace_back(num);
        return ret;
    }
};