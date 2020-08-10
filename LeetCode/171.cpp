class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size(), res = 0;
        for(auto c : s)
            if(--n) res += (c - 'A' + 1) * pow(26, n);
            else res += (c - 'A' + 1);
        return res;
    }
};