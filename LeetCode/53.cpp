class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0]; // 有可能 nums.size() = 1    
        for(size_t i = 0; i < nums.size(); ++i)
        {
            int sum = 0;
            for(size_t j = i; j < nums.size(); ++j)
            {
                sum += nums[j];
                if(sum > max)
                    max = sum;
            }   
        }
        return max;
    }
};
