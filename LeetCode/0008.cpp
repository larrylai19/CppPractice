class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int indicator = 1, mx = INT_MAX, idx = str.find_first_not_of(' ');
        if(idx == -1) return 0;
        if(str[idx] == '+' || str[idx] == '-') indicator = str[idx++] == '-' ? -1 : 1;
        while(isdigit(str[idx]))
        {
            res = res * 10 + (str[idx++] - '0');
            if(res > mx) return indicator == 1 ? INT_MAX : INT_MIN;
        }
        return res * indicator;
    }
};