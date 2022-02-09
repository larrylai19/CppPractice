class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxPos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (mxPos < i) return false;
            mxPos = max(i + nums[i], mxPos);
        }
        return true;
    }
};