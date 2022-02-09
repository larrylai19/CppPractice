class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> v;
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
            if (target - candidates[i] < 0) break;
            v.push_back(candidates[i]);
            populate(candidates, target - candidates[i], i, v, ret);
            v.pop_back();
        }
   }
};