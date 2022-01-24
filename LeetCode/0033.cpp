class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(true)
        {
            if(left == right)
                return -1;
            
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] > target)
                if(nums[0] > nums[mid])
                    right = mid;
                else
                    if(nums[0] > target)
                    
                        left = mid + 1;
                    else
                        right = mid;   
            
            if(nums[mid] < target)
                if(nums[0] > nums[mid])
                    if(nums[0] > target)
                        left = mid + 1;
                    else
                        right = mid;
                else
                    left = mid + 1;
        }
        return -1;
    }
};
