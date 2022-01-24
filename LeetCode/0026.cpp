class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int idx = 0;
        for (auto& n : nums) if (n != nums[idx]) nums[++idx] = n;
        return ++idx;
    }
};