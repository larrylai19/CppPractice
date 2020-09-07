class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        string tmp;
        stringstream ss(str);
        unordered_map<char, string> m;
        unordered_set<string> s;
        for(auto c : pattern)
        {
            ss >> tmp;
            //         two keys to one val || not right val
            if(!m.count(c) && s.count(tmp) || m.count(c) && tmp != m[c]) return false;
            m[c] = tmp, s.insert(tmp);
        }
        return ss.eof() ? true : false;
    }
};