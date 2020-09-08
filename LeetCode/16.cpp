class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size(), res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i{}; i < n - 2; ++i)
        {
            if(i && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                int tmp = nums[i] + nums[l] + nums[r];
                if(tmp == target) return tmp;
                res = abs(tmp - target) < abs(res - target) ? tmp : res;
                tmp > target ? --r : ++l;
            }
        }
        return res;
    }
};