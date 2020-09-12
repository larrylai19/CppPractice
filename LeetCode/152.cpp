class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int mx = nums[0], mn = mx, res = mx, n = nums.size();
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] < 0) swap(mx, mn);
            mx = max(mx * nums[i], nums[i]);
            mn = min(mn * nums[i], nums[i]);
            res = max(res, mx);
        }
        return res;
    }
};