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
    int romanToInt(string s) {
        int pos, res = 0;
        pair<string, int> dict1[] = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}};
        pair<string, int> dict2[] = {{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
        for(auto i : dict2)
            while((pos = s.find(i.first)) != -1)
                res += i.second, s[pos] = '*', s[++pos] = '*';
        for(auto i : dict1)
            while((pos = s.find(i.first)) != -1)
                res += i.second, s[pos] = '*';
        return res;
    }
};