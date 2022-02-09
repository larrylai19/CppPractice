class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int cur = 0;
        int steps = 0;
        
        while (cur < n - 1) {
            ++steps;
            int pre = cur;
            while (l <= pre) cur = max(nums[l] + l++, cur);
        }
        
        return steps;
    }
};