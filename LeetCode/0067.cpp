class Solution {
public:
    string addBinary(string a, string b)
    {
        string str;
        int i = a.length() - 1, j = b.length() - 1, c = 0;
        while(i >= 0 || j >= 0 || c)
        {
            if(i >= 0) c += a[i--] - '0';
            if(j >= 0) c += b[j--] - '0';
            str = char(c % 2 + '0') + str;
            c /= 2;
        }
        return str;
    }
};