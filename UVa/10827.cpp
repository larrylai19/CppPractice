#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/f4CYbx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int N;
int sum[76];
int table[151][76];

void read()
{
    int tmp;
    cin >> N;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
    {
        cin >> tmp;
        table[i][j] = table[i + N][j] = tmp;
    }
}

int max1D()
{
    int mx, mxRet, mn, mnRet, total;
    mx = mxRet = mn = mnRet = total = sum[0];

    for (int i = 1; i < N; ++i)
    {
        total += sum[i];

        mx = max(mx + sum[i], sum[i]);
        mxRet = max(mx, mxRet);
        
        mn = min(mn + sum[i], sum[i]);
        mnRet = min(mn, mnRet);
    }
    
    // 不可不選
    if (total == mnRet) return mxRet;
    return max(mxRet, total - mnRet);
}

void solve()
{
    int mx = INT_MIN;

    // max2D
    for (int t = 0; t < N; ++t)         // top
    {
        for (int b = t; b < t + N; ++b) // bottom
        {
            for (int i = 0; i < N; ++i) sum[i] += table[b][i];
            mx = max(max1D(), mx);
        }
        memset(sum, 0, sizeof(sum));
    }

    cout << mx << '\n';
}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        read();
        solve();
    }
}