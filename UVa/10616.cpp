#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fAF1Zx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int C;
int N, Q;
int D, M;
int nums[201];
int tmp[201];
long long dp[201][11];

void init()
{
    cin >> D >> M;

    // 將所有數字轉換到 0 ~ D 區間
    for (int i = 0; i < N; ++i)
    {
        tmp[i] = nums[i] % D;
        if (tmp[i] < 0) tmp[i] += D; // 同餘定理
    }

    memset(dp, 0, sizeof(dp));
}

void solve()
{
    for (int i = 0; i < N; ++i) cin >> nums[i];

    cout << "SET " << ++C << ":\n";

    int q = 0;
    while (q < Q)
    {
        init();

        dp[0][0] = 1;
        for (int i = 0; i < N; ++i) for (int j = M; j > 0; --j)
        {
            for (int k = tmp[i]; k <= 200; ++k) dp[k][j] += dp[k - tmp[i]][j - 1];
        }

        long long cnt = 0;
        for (int i = 0; i <= 200; i += D) cnt += dp[i][M];

        cout << "QUERY " << ++q << ": " << cnt << '\n';
    }
}

int main()
{
    while (cin >> N >> Q && N && Q) solve();
}