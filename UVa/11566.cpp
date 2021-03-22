#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fAhWWx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int N, X, T, K;
int V;
int favor[201];
int price[201];
int dp[23][1001]; // dp[i][j] 表最多選擇了 i 盤點心，總價格為 j 元

void read()
{
    memset(dp, 0, sizeof(dp));

    // 先將所有金額扣除茶費及服務費
    ++N;
    V = int((X * N) / 1.1 + 1e-9); // + 1e-9 是為了避免浮點數誤差
    V -= T * N;

    // 由於每個點心最多可點兩盤，所以放入兩個
    for (int i = 0, tmp; i < K; ++i)
    {
        int sum = 0; // 滿意度總和
        cin >> tmp;
        price[i << 1] = price[(i << 1) + 1] = tmp;
        for (int j = 0; j < N; ++j) cin >> tmp, sum += tmp;
        favor[i << 1] = favor[(i << 1) + 1] = sum;
    }
}

void solve()
{
    for (int i = 0; i < K * 2; ++i)
    {
        for (int j = N * 2; j > 0; --j) for (int k = price[i]; k <= V; ++k)
        {
            dp[j][k] = max(dp[j - 1][k - price[i]] + favor[i], max(dp[j - 1][k], dp[j][k]));
        }
    }

    int mx = INT_MIN;
    for (int i = 0; i <= 2 * N; ++i) mx = max(dp[i][V], mx);
    cout << setprecision(2) << fixed << (double)mx / N << '\n';
}

int main()
{
    while (cin >> N >> X >> T >> K && (N || X || T || K))
    {
        read();
        solve();
    }
}