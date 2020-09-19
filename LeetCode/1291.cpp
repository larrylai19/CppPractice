class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int ldigits = to_string(low).length(), hdigits = to_string(high).length();
        vector<int> ret;
        string str = "123456789";
        for(int i = ldigits; i <= hdigits; ++i) for(int j{}; j < 10 - i; ++j)
        {
            int tmp = atoi(str.substr(j, i).c_str());
            if(tmp > high) break;
            if(tmp >= low) ret.emplace_back(tmp);
        }
        return ret;
    }
};