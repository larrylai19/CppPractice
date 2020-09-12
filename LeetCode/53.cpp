class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int mx = nums[0], res = mx, n = nums.size();
        for(int i = 1; i < n; ++i)
        {
            mx = max(mx + nums[i], nums[i]);
            res = max(res, mx);
        }
        return res;
    }
};