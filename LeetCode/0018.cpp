class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> v;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            if (0L + nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (0L + nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            
            for (int j = n - 1; j > i + 2; --j) {
                if (j != n - 1 && nums[j] == nums[j + 1]) continue;
                
                int targetVal = target - (nums[i] + nums[j]);
                int l = i + 1, r = j - 1;
                
                while (l < r) {
                    if (nums[l] + nums[r] == targetVal) {
                        v.push_back({ nums[i], nums[l], nums[r], nums[j] });
                        
                        while (l < r && nums[l] == nums[l + 1]) ++l;
                        while (l < r && nums[r] == nums[r - 1]) --r;
                        ++l, --r;
                    }
                    else if (nums[l] + nums[r] < targetVal) ++l;
                    else --r;
                }
            }
        }
        
        return v;
    }
};