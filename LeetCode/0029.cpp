// ref: https://medium.com/@ChYuan/leetcode-29-divide-two-integers-%E5%BF%83%E5%BE%97-medium-91e5fccb29fa

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend >= 0 ^ divisor >= 0) ? -1 : 1;
        long long quotient = 0, sum = 0;
        
        long long dividendLL = dividend;
        dividendLL = abs(dividendLL);
        long long divisorLL = divisor;
        divisorLL = abs(divisorLL);
        
        for (int i = 31; i >= 0; --i) {
            if ((dividendLL >> i) >= divisorLL) {
                dividendLL -= (divisorLL << i);
                quotient += (1LL << i);
            }
        }
        
        if (sign * quotient > INT_MAX) return INT_MAX;
        
        return sign * quotient;
    }
};