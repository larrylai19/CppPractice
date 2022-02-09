class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ret = 0, n = nums1.size();
        unordered_map<int, int> m1, m2;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++m1[nums1[i] + nums2[j]];
                ++m2[nums3[i] + nums4[j]];
            }
        }
        
        for (const auto& [v, t] : m1) ret += t * m2[-v];

        return ret;
    }
};