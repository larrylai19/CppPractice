class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int l = 0;
        for (auto& n : nums) if (n != val) nums[l++] = n;
        return l;
    }
};