class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;        
        vector<int> allChar(26);
        vector<int> currChar(26);
        
        for (auto& c : p) ++allChar[c - 'a'];
        
        int l = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++currChar[s[i] - 'a'];
            if (i >= p.length()) --currChar[s[l++] - 'a'];
            if (currChar == allChar) ret.push_back(l);
        }
        
        return ret;
    }
};