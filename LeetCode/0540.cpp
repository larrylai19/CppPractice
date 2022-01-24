class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {             
        int begin = 0, end = nums.size(), mid;
        while(end - begin != 1)
        {
            mid = (begin + end) / 2;
            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];
            if(nums[mid - 1] != nums[mid] && nums[mid] == nums[mid + 1])
                if(mid % 2)
                    end = mid;
                else
                    begin = mid + 2;
            else if(nums[mid - 1] == nums[mid] && nums[mid] != nums[mid + 1])
                if(mid % 2)
                    begin = mid + 1;
                else
                    end = mid - 1;
        }
        return nums[begin];
    }
};