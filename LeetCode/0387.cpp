class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {}, n = s.size();
        for(auto i : s)
            ++count[i - 'a'];
        for(int i = 0; i < n; ++i)
            if(count[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};