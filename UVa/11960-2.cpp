#include <bits/stdc++.h>

using namespace std;

/*
reference:
    https://hackmd.io/@SCIST/BasicMath3#UVa-11960
    質數篩: http://web.ntnu.edu.tw/~algo/Prime.html#3
*/

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int maxN = (int)1e6 + 1;

int N;
int prime[maxN];  // 紀錄每個數字的最小質因數
int ans[maxN];

void preProcessing()
{
    // 質數篩
    for (long long i = 2; i < maxN; ++i)
    {
        if (prime[i]) continue;

        prime[i] = (int)i;
        for (long long j = i * i; j < maxN; j += i)
            if (!prime[j]) prime[j] = (int)i;
    }

    // 計算每個數的因數個數，找出每個質因數的最大次方，可能性就是最大次方加一 ( 可不選 )
    fill(ans, ans + maxN, 1);
    for (int i = 2; i < maxN; ++i)
    {
        int tmp = i;
        while (tmp != 1)
        {
            int p = prime[tmp], cnt = 0;
            while (!(tmp % p)) tmp /= p, ++cnt;
            ans[i] *= ++cnt;
        }
    }

    int n = 2, _max = ans[2];
    for (int i = 3; i < maxN; ++i)
    {
        if (ans[i] >= _max) _max = ans[i], n = i;
        ans[i] = n;
    }
}

void solve()
{
    int T, tmp;
    cin >> T;
    while (T--)
    {
        cin >> tmp;
        cout << ans[tmp] << '\n';
    }
}

int main()
{
    preProcessing();
    solve();
}