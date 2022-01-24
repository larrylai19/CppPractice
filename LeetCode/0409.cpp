class Solution {
public:
    int longestPalindrome(string s) {
        int l = 0, odd = 0;
        unordered_map<char, int> _m;
        for(auto c : s) ++_m[c];
        for(auto m : _m) { if(m.second % 2) odd = 1; l += m.second / 2 * 2; }
        return l + odd;
    }
};