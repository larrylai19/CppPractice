class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int target = 0, maxLength = 0, n = nums.size();
        unordered_map<int, int> map;
        map.insert({0, -1});
        for(int i = 0; i < n; ++i)
        {
            target += (nums[i] == 0) ? -1 : 1;
            if(map.count(target))
                maxLength = max(maxLength, i - map[target]);
            else
                map[target] = i;
        }
        return maxLength;
    }
};