// ref: https://youtu.be/StH5vntauyQ

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int maxL = height[l], maxR = height[r];
        int ret = 0;
        
        while (l < r) {
            if (maxL < maxR) {
                ret += maxL - height[l];
                maxL = max(height[++l], maxL);
            } else {
                ret += maxR - height[r];
                maxR = max(height[--r], maxR);
            }
        }
        
        return ret;
    }
};