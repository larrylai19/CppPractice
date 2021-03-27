#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int A, B, C;
long long cuboid[21][21][21];
long long sum2D[21][21];
long long sum[21];

void read()
{
    cin >> A >> B >> C;
    for (int i = 0; i < A; ++i) for (int j = 0; j < B; ++j) for (int k = 0; k < C; ++k)
        cin >> cuboid[i][j][k];
}

long long max1D()
{
    long long mx, ret;
    mx = ret = sum[0];

    for (int i = 1; i < C; ++i)
    {
        mx = max(mx + sum[i], sum[i]);
        ret = max(mx, ret);
    }

    return ret;
}

long long max2D()
{
    long long mx = LLONG_MIN;

    for (int i = 0; i < B; ++i)
    {
        for (int j = i; j < B; ++j)
        {
            for (int k = 0; k < C; ++k) sum[k] += sum2D[j][k];
            mx = max(max1D(), mx);
        }
        memset(sum, 0, sizeof(sum));
    }

    return mx;
}

void solve()
{
    long long mx = LLONG_MIN;
    
    // max3D
    for (int i = 0; i < A; ++i)
    {
        for (int j = i; j < A; ++j)
        {
            for (int k = 0; k < B; ++k) for (int l = 0; l < C; ++l) sum2D[k][l] += cuboid[j][k][l];
            mx = max(max2D(), mx);
        }
        memset(sum2D, 0, sizeof(sum2D));
    }

    cout << mx << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        read();
        solve();
        if (T) cout << '\n';
    }
}