class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> table;
        string temp;
        for(auto& i : strs)
        {
            temp = i;
            sort(temp.begin(), temp.end());
            table[temp].push_back(i);
        }
        for(auto& i : table)
            res.push_back(i.second);
        return res;
    }
};