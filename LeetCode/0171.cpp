class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size() - 1, res = 0;
        for(auto c : s)
            res += (c - 'A' + 1) * pow(26, n--);
        return res;
    }
};