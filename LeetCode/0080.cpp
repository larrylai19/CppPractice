class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, cnt = 1, n = nums.size();
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[idx]) {
                if (cnt < 2) {
                    nums[++idx] = nums[i];
                    ++cnt;
                }
            } else {
                nums[++idx] = nums[i];
                cnt = 1;
            }
        }
        
        return idx + 1;
    }
};