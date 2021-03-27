#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fXQTNx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int C;
int N, M, K;
int t, b;
int price, mxArea;
int sum[101];
int table[101][101];

void read()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> table[i][j];
}

void max1D()
{
    int l = 0, s = 0, area;

    for (int i = 0; i < M; ++i)
    {
        s += sum[i];
        while (s > K) s -= sum[l++];

        area = (b - t + 1) * (i - l + 1);
        if (area > mxArea) mxArea = area, price = s;
        else if (area == mxArea) price = min(s, price);
    }
}

void solve()
{
    mxArea = 0;
    price = INT_MAX;

    // max2D
    for (t = 0; t < N; ++t)
    {
        for (b = t; b < N; ++b)
        {
            for (int i = 0; i < M; ++i) sum[i] += table[b][i];
            max1D();
        }
        memset(sum, 0, sizeof(sum));
    }

    cout << "Case #" << ++C << ": " << mxArea << ' ' << price << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        read();
        solve();
    }
}