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
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] > 0) break;
            if (i && nums[i] == nums[i - 1]) continue;
            int target = -nums[i], l = i + 1, r = n - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] == target)
                {
                    v.push_back({ nums[i], nums[l], nums[r] });
                    // 避免儲存到一樣的結果
                    while(l < r && nums[l] == nums[l + 1]) ++l;
                    while(l < r && nums[r] == nums[r - 1]) --r;
                    ++l, --r;
                }
                else if (nums[l] + nums[r] < target) ++l;
                else --r;
            }
        }
        return v;
    }
};