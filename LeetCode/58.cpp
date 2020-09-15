class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int idx = s.find_last_not_of(' '), length{};
        while(idx >= 0 && isalpha(s[idx--])) ++length;
        return length;
    }
};