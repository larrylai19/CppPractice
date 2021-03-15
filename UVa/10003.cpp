#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fZFwfx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int inf = (int)1e9;

int l, n;
int dp[52][52]; // dp[i][j] 表切割 i 及 j 中所有切割點的最小花費
int cut[52];    // 木頭切割點

void read()
{
    cin >> n;
    cut[++n] = l;
    for (int i = 1; i < n; ++i) cin >> cut[i];
}

void solve()
{
    // args:
    // w -> wide  枚舉的區間寬度
    // l -> left  左端點
    // r -> right 右端點
    // m -> mid   中間
    for (int w = 2; w <= n; ++w) for (int l = 0; l < n - 1; ++l)
    {
        int r = l + w;
        if (r > n) break;
        dp[l][r] = INT_MAX;
        for (int m = l + 1; m < r; ++m)
            dp[l][r] = min(dp[l][m] + dp[m][r] + cut[r] - cut[l], dp[l][r]);
    }
    cout << "The minimum cutting is " << dp[0][n] << ".\n";
}

int main()
{
    while (cin >> l && l)
    {
        read();
        solve();
    }
}