#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/feem5x

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int T;
int n;
int mx;
int weights[2001];
int LIS[2001];
int LDS[2001];

void read()
{
    mx = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> weights[i], LIS[i] = LDS[i] = 1;
}

void solve()
{
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j > i; --j)
        {
            // 若 j 能接在 i 後面 ( LIS )
            if (weights[i] > weights[j]) LIS[i] = max(LIS[j] + 1, LIS[i]);
            // 若 j 能接在 i 後面 ( LDS )
            if (weights[i] < weights[j]) LDS[i] = max(LDS[j] + 1, LDS[i]);
        }
        mx = max(LIS[i] + LDS[i] - 1, mx);
    }

    cout << mx << '\n';
}

int main()
{
    cin >> T;
    while (T--)
    {
        read();
        solve();
    }
}