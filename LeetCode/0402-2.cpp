class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k)
            return "0";
        string res;
        for(auto i : num)
        {
            while(k && !res.empty() && res.back() > i)
                res.pop_back(), --k;
            if(!res.empty() || i != '0')
                res.push_back(i);
        }
        while(k--)
            res.pop_back();
        return res.empty() ? "0" : res;
    }
};