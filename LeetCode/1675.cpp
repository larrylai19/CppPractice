// ref: https://www.youtube.com/watch?v=l_o4fp6BHYY

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for (auto& n : nums) s.insert(n & 1 ? n * 2 : n);
        int ret = *s.rbegin() - *s.begin();
        while ((*s.rbegin() & 1) == 0) {
            s.insert(*s.rbegin() / 2);
            s.erase(*s.rbegin());
            ret = min(*s.rbegin() - *s.begin(), ret);            
        }
        return ret;
    }
};