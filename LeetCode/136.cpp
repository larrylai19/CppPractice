class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(size_t i = 1; i < nums.size(); ++i)
            ans ^= nums[i];
        return ans;
    }
};