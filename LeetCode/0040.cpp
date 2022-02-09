class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        vector<vector<int>> ret;
        populate(candidates, target, 0, v, ret);
        return ret;
    }
    
private:
    void populate(vector<int>& candidates, int target, int idx, vector<int>& v, vector<vector<int>>& ret) {
        if (target == 0) {
            ret.push_back(v);
            return;
        }
        
        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            v.push_back(candidates[i]);
            populate(candidates, target - candidates[i], i + 1, v, ret);
            v.pop_back();
        }
    }
};