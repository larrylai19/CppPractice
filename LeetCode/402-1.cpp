class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k)
            return "0";
        int digits = n - k;
        string res;
        for(auto i : num)
        {
            while(k && !res.empty() && res.back() > i)
                res.pop_back(), --k;
            res.push_back(i);
        }
        // 避免結果太長
        res.resize(digits);
        while(!res.empty() && res.front() == '0')
            res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};