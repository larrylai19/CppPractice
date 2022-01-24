class Solution {
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1) return s;
        int n = s.length(), j = -1;
        bool reverse = false;
        string res;
        vector<string> v(numRows);
        for(auto& c : s)
        {
            if(!reverse)
            {
                v[++j] += c;
                if(j >= numRows - 1) reverse = true;
            }
            else
            {
                v[--j] += c;
                if(!j) reverse = false;
            }
        }
        for(auto& str : v) res += str;
        return res;
    }
};