class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        multiset<long> ms;
        for(int j = 0; j < nums.size(); ++j)
        {
            if(j > k) ms.erase(ms.lower_bound(nums[j - k - 1]));
            auto iter = ms.lower_bound(long(nums[j]) - long(t));
            if(iter != ms.end() && *iter <= long(nums[j]) + long(t)) return true;
            ms.insert(nums[j]);
        }
        return false;
    }
};