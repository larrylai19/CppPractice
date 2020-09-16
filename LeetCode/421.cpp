class Solution {
public:
    int findMaximumXOR(vector<int>& nums)
    {
        int ret{}, mask{};
        for(int i = 1 << 30; i; i >>= 1)
        {
            mask |= i;
            unordered_set<int> u_set;
            for(auto num : nums) u_set.insert(mask & num);
            for(auto val : u_set) if(u_set.count(val ^ (ret | i))) { ret |= i; break; }
        }
        return ret;
    }
};