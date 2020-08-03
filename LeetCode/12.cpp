class Solution {
public:
    string intToRoman(int num) {
        string res;
        int pos = 12;
        pair<string, int> dict[13] = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
        while(num > 0)
        {
            while(pos && dict[pos].second > num)
                --pos;
            while(num >= dict[pos].second)
                res += dict[pos].first, num -= dict[pos].second;
        }
        return res;
    }
};