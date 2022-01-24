class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k)
            return "0";
        int size = 0;
        for(auto i : num)
        {
            while(k && size && num[size - 1] > i)
                --size, --k;
            if(size || i != '0')
                num[size++] = i;
        }
        num.resize(size - k);
        return num.empty() ? "0" : num;
    }
};