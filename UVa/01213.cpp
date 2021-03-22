#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fAybWx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int primeCnt;      // 質數個數
int primes[187];   // 只有 187 個質數
bool visited[1121];
int dp[1121][15];

// get all primes
void sieve()
{
    for (int i = 2; i <= 1120; ++i)
    {
        if (visited[i]) continue;
        primes[primeCnt++] = i;
        for (int j = i + i; j <= 1120; j += i) visited[j] = true;
    }
}

void compute()
{
    for (auto& v : primes) for (int i = 1120; i >= v; --i)
    {
        if (i == v) dp[v][1] = 1;
        for (int j = 2; j <= 14; ++j) dp[i][j] += dp[i - v][j - 1];
    }
}

void solve()
{
    int n, k;
    while (cin >> n >> k && n && k) cout << dp[n][k] << '\n';
}

int main()
{
   sieve();
   compute();
   solve();
}