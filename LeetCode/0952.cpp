class DSU
{
public:
    DSU(int n) : p(n) { for(int i = 0; i < n; ++i) p[i] = i; }
    
    void _union(int x, int y) { p[_find(x)] = p[_find(y)]; }
    
    int _find(int x) { if(p[x] != x) p[x] = _find(p[x]); return p[x]; }
private:
    vector<int> p;
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end());
        DSU dsu(n + 1);
        for(auto a : A) for(int i = 2; i <= sqrt(a); ++i)
            if(!(a % i)) dsu._union(a, i), dsu._union(a, a / i);
        unordered_map<int, int> m;
        int ans = 1;
        for(auto a : A) ans = max(ans, ++m[dsu._find(a)]);
        return ans;
    }
};