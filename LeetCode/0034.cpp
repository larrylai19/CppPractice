class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int idx = binarySearch(nums, target, 0, n);
        if (idx == -1) return { -1, -1 };
        
        int l = idx, r = idx;
        while (l > 0 && nums[l] == nums[l - 1]) --l;
        while (r < n && nums[r] == nums[r + 1]) ++r;
        return { l, r };
    }

private:
    int binarySearch(vector<int>& nums, int target, int l, int r) {
        if (l > r) return -1;
        
        int m = (l + r) / 2;
        
        if (nums[m] == target) return m;
        if (nums[m] > target) return binarySearch(nums, target, l, m - 1);
        return binarySearch(nums, target, m + 1, r);
    }
};