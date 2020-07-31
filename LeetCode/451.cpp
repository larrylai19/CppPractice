// fast IO
static auto __ = []() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    static bool cmp(const pair<char, int>& l,const pair<char, int>& r)
    {
        return l.second > r.second;
    }
    string frequencySort(string s) {
        int length = s.size();
        string res;
        res.reserve(length);
        unordered_map<char, int> hash;
        for(auto c : s)
            ++hash[c];
        vector<pair<char, int>> v(hash.begin(), hash.end());
        sort(v.begin(), v.end(), cmp);
        for(auto i : v)
            res.append(i.second, i.first);
        return res;
    }
};