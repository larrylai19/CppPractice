class Solution {
public:
    int mySqrt(int x) {
        return dfs(0, x, x);
    }
    
private:
    long long dfs(long long l, long long r, int x) {
        long long m = (l + r) / 2;
        
        if (m * m <= x) {
            if ((m + 1) * (m + 1) > x) return m;
            return dfs(m + 1, r, x);
        }
        
        return dfs(l, m - 1, x);
    }
};