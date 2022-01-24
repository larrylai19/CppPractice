class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty()) return {};
        vector<vector<char>> dict = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<string> v;
        dfs(string(), digits, 0, v, dict);
        return v;
    }
private:
    void dfs(string str, string& digits, int idx, vector<string>& v, vector<vector<char>>& dict)
    {
        if(idx == digits.size()) { v.emplace_back(str); return; }
        for(auto c : dict[digits[idx] - '0' - 2]) dfs(str + c, digits, idx + 1, v, dict);
    }
};