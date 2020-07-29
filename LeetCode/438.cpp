class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ls = s.size(), lp = p.size();
        vector<int> vs(26), vp(26), res;
        for(auto c : p)
            ++vp[c - 'a'];
        for(int i = 0; i < ls; ++i)
        {
            if(i >= lp)
                --vs[s[i - lp] - 'a'];
            ++vs[s[i] - 'a'];
            if(vs == vp)
                res.push_back(i - lp + 1);
        }
        return res;
    }
};