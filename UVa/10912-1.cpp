#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int INF = (int)1e9;

int L, S;
int C;
int dp[27][352];

void compute()
{
    dp[0][0] = 1;
    FOR(i, 1, 27) for (int j = 26; j > 0; --j) FOR(k, i, 352)
        dp[j][k] += dp[j - 1][k - i];
}

int main()
{
    compute();
    while (cin >> L >> S && (L || S))
    {
        cout << "Case " << ++C << ": ";
        if (L > 27 || S > 351) cout << "0\n";
        else cout << dp[L][S] << '\n';
    }
}