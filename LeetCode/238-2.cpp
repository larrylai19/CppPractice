class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightProduct(n, 1);
        for(int i = n - 2; i >= 0; --i)
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
        for(int i = 0, left = 1; i < n; ++i)
            rightProduct[i] *= left,    left *= nums[i];
        return rightProduct;
    }
};