#include <bits/stdc++.h>

using namespace std;

/*
reference:
    https://ppt.cc/fr07lx
    https://ppt.cc/fzn4hx
*/

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int n, k, m;
long long dp[51][51][51];

void compute()
{
    // 當只有一個 bar 時，對於 m >= n，dp[n][1][m] = 1 ( 只有一個黑色的 bar )
    for (int n = 1; n <= 50; ++n) for (int m = n; m <= 50; ++m) dp[n][1][m] = 1;
    for (int n = 1; n <= 50; n++) for (int k = 1; k <= 50; k++) for (int m = 1; m <= 50; m++)
    {
        // 由於最多 n 個 units，因此當 m > n 時，dp[n][k][m] = dp[n][k][n]，也就是無法再接 bar 上去
        if (m > n) { dp[n][k][m] = dp[n][k][n]; continue; }
        // 新接上的 bar 寬度為 1 ~ m
        for (int i = 1; i <= m; i++) dp[n][k][m] += dp[n - i][k - 1][m];
    }
}

int main()
{
    compute();
    while (cin >> n >> k >> m) cout << dp[n][k][m] << '\n';
}