#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fgtWRx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int N;
int P;
int hartalCycles[101];

void read()
{
    cin >> N >> P;
    for (int i = 0; i < P; ++i) cin >> hartalCycles[i];
}

void solve()
{
    int hartal = 0;
    for (int i = 1; i <= N; ++i)
    {
        // 跳過星期五和六
        if (i % 7 == 6) { ++i; continue; }

        for (int j = 0; j < P; ++j)
            if (i % hartalCycles[j] == 0) { ++hartal; break; }
    }
    cout << hartal << '\n';
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