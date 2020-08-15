class Solution {
public:
    string longestPalindrome(string s) {
        _s = s, n = s.size();
        int len = INT_MIN, start, curLen;
        for(int i = 0; i < n; ++i)
        {
            curLen = max(getLength(i, i), getLength(i, i + 1));
            if(curLen > len) len = curLen, start = i - (curLen - 1) / 2;
        }
        return s.substr(start, len);
    }
private:
    string _s;
    int n;
    
    int getLength(int l, int r)
    {
        while(l >= 0 && r < n && _s[l] == _s[r]) --l, ++r;
        return r - l - 1;
    }
};