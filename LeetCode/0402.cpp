// ref: https://www.cnblogs.com/grandyang/p/5883736.html

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.length()) return "0";
        
        string ret;
        int minLength = num.length() - k;
        
        for (auto& c : num) {
            while (k && ret.length() && ret.back() > c) {
                ret.pop_back();
                --k;
            }
            ret.push_back(c);
        }
        
        ret.resize(minLength);        
        while (ret.length() > 1 && ret[0] == '0') ret.erase(ret.begin());
        
        return ret;
    }
};