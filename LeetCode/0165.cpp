class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        int i{}, j{}, n1 = version1.length(), n2 = version2.length();
        while(i < n1 || j < n2)
        {
            int tmp1{}, tmp2{};
            while(i < n1 && version1[i] != '.') tmp1 = tmp1 * 10 + version1[i++] - '0';
            while(j < n2 && version2[j] != '.') tmp2 = tmp2 * 10 + version2[j++] - '0';
            ++i, ++j;
            if(tmp1 != tmp2) return tmp1 > tmp2 ? 1 : -1;
        }
        return 0;
    }
};