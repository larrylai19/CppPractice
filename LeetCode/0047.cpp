static auto __ = [] {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> v;
        bool isUsed[8] = {};
        sort(nums.begin(), nums.end());
        dfs(isUsed, v, nums, ret);
        return ret;
    }
    
private:
    void dfs(bool isUsed[], vector<int>& v, vector<int>& nums, vector<vector<int>>& ret) {
        if (v.size() == nums.size()) {
            ret.push_back(v);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (isUsed[i]) continue;
            if (i && nums[i] == nums[i - 1] && !isUsed[i - 1]) continue;
            
            v.push_back(nums[i]);
            isUsed[i] = true;
            dfs(isUsed, v, nums, ret);
            isUsed[i] = false;
            v.pop_back();
        }
    }
};