class Solution {
public:
    double myPow(double x, int n)
    {
        if(!n) return 1;
        auto tmp = myPow(x, n / 2);
        if(!(n % 2)) return tmp * tmp;
        return n > 0 ? x * tmp * tmp : tmp * tmp / x;
    }
};