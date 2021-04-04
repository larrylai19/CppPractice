#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const long long money[] = { 1, 5, 10, 25, 50 };
long long dp[30001];

void CoinChange()
{
    dp[0] = 1;
    for (auto& m : money) for (long long i = m; i <= 30000; ++i)
        dp[i] += dp[i - m];
}

void solve()
{
    int n;
    while (cin >> n)
    {
        if (dp[n] == 1) cout << "There is only 1 way ";
        else cout << "There are " << dp[n] << " ways ";
        cout << "to produce " << n << " cents change.\n";
    }
}

int main()
{
    CoinChange();
    solve();
}