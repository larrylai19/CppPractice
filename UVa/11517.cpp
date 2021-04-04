#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fp0yAx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int INF = (int)1e9;

int N, P;
int sum;
int C[101];
int dp[20001];

void init()
{
    for (int i = 1; i <= sum; ++i) dp[i] = INF;
}

void read()
{
    cin >> P >> N;
    sum = 0; // 一種面額只能用一次，紀錄最少需要做到多少錢
    for (int i = 0; i < N; ++i)
    {
        cin >> C[i];
        if (sum < P) sum += C[i];
    }
}

void CoinChange()
{
    for (int i = 0; i < N; ++i)
    {
        // 反向做，避免多次使用相同的面額
        for (int j = sum; j >= C[i]; --j) dp[j] = min(dp[j - C[i]] + 1, dp[j]);
    }
}

void solve()
{
    int p = P;
    while (p < sum && dp[p] == INF) ++p;
    cout << p << ' ' << dp[p] << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        read();
        init();
        CoinChange();
        solve();
    }
}