#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fMOZjx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int N, K;
int dp[101][101]; // dp[i][j] 表 i 拆成 j 個數字的方法數

void compute()
{
    for (int i = 0; i < 101; ++i) dp[i][1] = 1;
    for (int i = 0; i < 101; ++i) for (int j = 1; j < 101; ++j) for (int k = 0; k <= i; ++k)
        dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 1000000;
}

int main()
{
    compute();
    while (cin >> N >> K && N && K) cout << dp[N][K] << '\n';
}