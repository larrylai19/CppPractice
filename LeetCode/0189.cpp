class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        auto orgNums = nums;
        
        for (int i = 0, j = n - k; i < n; ++i, ++j) {
            if (j >= n) j -= n;
            nums[i] = orgNums[j];
        }
    }
};