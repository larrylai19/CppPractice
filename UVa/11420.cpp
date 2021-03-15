#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fCBrlx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int n, s;
long long dp[67][67][2]; // dp[i][j][0] 表有 i 個櫃子，j 個處於安全狀態，且最上層的櫃子沒有鎖
                         // dp[i][j][1] 表有 i 個櫃子，j 個處於安全狀態，且最上層的櫃子有鎖

void compute()
{
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;

    for (int i = 2; i < 66; ++i)
    {
        // 只有一個安全且最上層有鎖 -> 加一層沒鎖
        // 沒有任何安全且最上層沒鎖 -> 加一層沒鎖
        dp[i][0][0] = dp[i - 1][1][1] + dp[i - 1][0][0];
        for (int j = 1; j <= i; ++j)
        {
            // 加一層沒鎖
            dp[i][j][0] = dp[i - 1][j + 1][1] + dp[i - 1][j][0];
            // 加一層有鎖
            dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
        }
    }
}

int main()
{
    compute();
    while (cin >> n >> s && !(n < 0 && s < 0))
        cout << dp[n][s][0] + dp[n][s][1] << '\n';
}