// ref: https://www.cnblogs.com/grandyang/p/6395843.html

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        
        for (auto& n : nums) {
            unordered_map<int, int> tmp;
            for (const auto& [k, v] : dp) {
                tmp[k + n] += v;
                tmp[k - n] += v;
            }
            dp = tmp;
        }
        
        return dp[S];
    }
};