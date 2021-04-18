#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define CLR(c) memset(c, 0, sizeof(c))

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int MXN = 10001;

int N;
int l;
int n[MXN];
int seq[MXN];
int L[MXN];
int LR[MXN];

void init()
{
    CLR(seq);
    l = 0;
}

void read()
{
    FOR(i, 0, N) cin >> n[i], L[i] = LR[i] = 1;
}

void LIS()
{
    FOR(i, 0, N)
    {
        int pos = lower_bound(seq, seq + l, n[i]) - seq;
        seq[pos] = n[i];
        L[i] = pos + 1;
        if (pos == l) ++l;
    }

    init();
    
    for (int i = N - 1; i >= 0; --i)
    {
        int pos = lower_bound(seq, seq + l, n[i]) - seq;
        seq[pos] = n[i];
        LR[i] = pos + 1;
        if (pos == l) ++l;
    }
}

void solve()
{
    int mx = 1;
    FOR(i, 0, N) mx = max(min(L[i], LR[i]) * 2 - 1, mx);
    cout << mx << '\n';
}

int main()
{
    while (cin >> N)
    {
        read();
        init();
        LIS();
        solve();
    }
}