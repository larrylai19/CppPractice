#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fzYlzx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int inf = (int)1e9;

int T;
int X;
int winds[1005][10]; // winds[i][j] 表第 i 段，第 j 層的風速
int dp[1005][10];    // dp[i][j] 表飛機到達第 i 段，第 j 層所需的最小花費

void read()
{
    cin >> X;
    X /= 100;

    for (int i = 9; i >= 0; --i) for (int j = 0; j < X; ++j)
        cin >> winds[j][i], dp[j][i] = inf;
}

void solve()
{
    dp[0][0] = 0; // 起點

    for (int i = 1; i <= X; ++i) for (int j = 0; j < 10; ++j)
    {
        int mn = INT_MAX;
        if (j > 0)
        {
            mn = min(dp[i - 1][j] + 30 - winds[i - 1][j], mn);         // 從 i - 1 平飛到 i
            mn = min(dp[i - 1][j - 1] + 60 - winds[i - 1][j - 1], mn); // 從 i - 1 向上飛到 i
        }
        if (j < 9) mn = min(dp[i - 1][j + 1] + 20 - winds[i - 1][j + 1], mn); // 從 i - 1 向下飛到 i
        dp[i][j] = mn;
    }

    cout << dp[X][0] << "\n\n";
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