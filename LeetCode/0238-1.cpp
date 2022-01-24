class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), all = 1, index = -1;
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i)
            if(nums[i] != 0)
                all *= nums[i];
            else if(index == -1)
               index = i;
            else
                return res;
        if(index == -1)
            for(int i = 0; i < n; ++i)
                res[i] = all / nums[i];
        else
            res[index] = all;
        return res;
    }
};