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
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(auto num : nums)
            if(nums[abs(num) - 1] < 0)
                v.push_back(abs(num));
            else
                nums[abs(num) - 1] *= -1;
        return v;
    }
};