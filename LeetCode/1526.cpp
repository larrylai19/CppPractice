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
    int minNumberOperations(vector<int>& target) {
        int res = 0, pre = 0;
        for(auto i : target)
        {
            if(i > pre)
                res += i - pre;
            pre = i;
        }
        return res;
    }
};