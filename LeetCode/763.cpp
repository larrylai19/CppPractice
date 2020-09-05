class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size(), l = 0, r = 0;
        vector<int> v, lastIdx(26);
        for(int i = 0; i < n; ++i) lastIdx[S[i] - 'a'] = i;
        for(int i = 0; i < n; ++i)
        {
            r = max(r, lastIdx[S[i] - 'a']);
            if(i == r) v.emplace_back(r - l + 1), l = ++r;
        }
        return v;
    }
};