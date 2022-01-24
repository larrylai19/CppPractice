class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        nums.insert(begin(nums), 0);
        for(int i = 0; i < nums.size(); ++i)
            while(nums[i] != i && nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]]) swap(nums[i], nums[nums[i]]);
        for(int i = 1; i < nums.size(); ++i) if(nums[i] != i) return i;
        return nums.size();
    }
};