#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int INF = (int)1e9;

int n, s;
pair<int, int> coin[41]; // Conventional, InfoTechnological
int dp[301][301];

void init()
{
    for (int i = 0; i <= 300; ++i) for (int j = 0; j <= 300; ++j) dp[i][j] = INF;
    dp[0][0] = 0;
}

void read()
{
    cin >> n >> s;
    s *= s;
    for (int i = 0; i < n; ++i) cin >> coin[i].first >> coin[i].second;
}

void CoinChange()
{
    for (int k = 0; k < n; ++k)
    {
        auto& [C, I] = coin[k];
        for (int i = C; i <= 300; ++i)
        {
            for (int j = I; j <= 300; ++j)
                dp[i][j] = min(dp[i - C][j - I] + 1, dp[i][j]);
        }
    }
}

void solve()
{
    int mn = INF;
    for (int i = 0; i <= 300; ++i) for (int j = 0; j <= 300; ++j)
        if (i * i + j * j == s) mn = min(dp[i][j], mn);

    if (mn == INF) { cout << "not possible\n"; return; }
    cout << mn << '\n';
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