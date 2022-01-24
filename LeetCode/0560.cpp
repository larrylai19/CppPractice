class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(!n)
            return 0;
        unordered_map<int, int> hash;
        hash.reserve(n);
        int count = 0, sum = 0;
        for(auto& i : nums)
        {
            ++hash[sum];
            sum += i;
            count += hash[sum - k];
        }
        return count;
    }
};