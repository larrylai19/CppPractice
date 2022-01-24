class Solution {
public:
    char findTheDifference(string s, string t)
    {
        char ch{};
        for(const auto& c : (s + t)) ch ^= c;
        return ch;
    }
};