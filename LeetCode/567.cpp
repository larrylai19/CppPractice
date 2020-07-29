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
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        vector<int> v1(26), v2(26);
        for(auto c : s1)
            ++v1[c - 'a'];
        for(int i = 0; i < l2; ++i)
        {
            if(i >= l1)
                --v2[s2[i - l1] - 'a'];
            ++v2[s2[i] - 'a'];
            if(v1 == v2)
                return true;
        }
        return false;
    }
};