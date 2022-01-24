class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num, count = 0;
        for(auto i : nums)
            if(i == num)
                ++count;
            else if(--count <= 0)
                num = i, count = 1;
        return num;
    }
};