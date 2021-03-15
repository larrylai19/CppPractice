#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fOSfWx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int GCD(int x, int y)
{
    if (y % x == 0) return x;
    return GCD(y % x, x);
}

int N;
int a, b;
int mx;
int stus[1001];

void init()
{
    mx = INT_MIN;
}

void read()
{
    cin >> a >> b;
    for (int i = 0; i < N; ++i) cin >> stus[i], mx = max(mx, stus[i] *= 6);
}

void solve()
{
    int x, y;
    int mn = INT_MAX;
    int q1, q2; // 餐點量

    for (auto& time : { 1, 2, 3 }) for (int i = 0; i < N; ++i)
    {
        // 有學生需要跑餐廳超過三次
        if ((q1 = stus[i] / time) * 3 < mx) continue;

        x = y = 0;
        for (int j = 0; j < N; ++j)
        {
            q2 = stus[j];
            while (q2 > q1) q2 -= q1, ++y;
            x += q1 - q2;
            ++y;
        }

        mn = min(a * x + 6 * b * y, mn);
    }

    // 約分
    int _gcd = GCD(mn, 6);
    if (_gcd == 6) cout << mn / 6 << '\n';
    else cout << mn / _gcd << " / " << 6 / _gcd << '\n';
}

int main()
{
    while (cin >> N && N)
    {
        init();
        read();
        solve();
    }
}