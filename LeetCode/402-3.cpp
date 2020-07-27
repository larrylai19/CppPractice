class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k)
            return "0";
        int digits = n - k, index = 0;
        for(auto i : num)
        {
            while(k && index && num[index - 1] > i)
                --index, --k;
            if(index || i != '0')
                num[index++] = i;
        }
        while(k--)
            --index;
        num.resize(index);
        return num.empty() ? "0" : num;
    }
};