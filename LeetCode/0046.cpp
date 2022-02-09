class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> v;
        bool isUsed[6] = {};
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
            
            v.push_back(nums[i]);
            isUsed[i] = true;
            dfs(isUsed, v, nums, ret);
            isUsed[i] = false;
            v.pop_back();
        }
    }
};