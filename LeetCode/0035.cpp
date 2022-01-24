class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        return binarySearch(nums, target);
        //return lower_bound(begin(nums), end(nums), target) - begin(nums);
    }
    
private:
    int binarySearch(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (target > nums[mid]) l = mid + 1;
            else r = mid;
        }
        return r;
    }
};