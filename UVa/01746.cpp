#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fqz3Sx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int N;
int quotes[101]; // 題目給的測資
int dummy[101];  // 用來模擬的陣列

void read()
{
    for (int i = 0; i < N; ++i) cin >> quotes[i];
}

void solve()
{
    // 模擬 k，暴力法檢查 k 是否可行
    for (int k = min(quotes[0], quotes[N - 1]); k > 0; --k)
    {
        memcpy(dummy, quotes, N * sizeof(int));
        int l = 0, r = N - 1, tmp = k;

        while (l < N && r >= 0 && dummy[l] >= tmp && dummy[r] >= tmp)
        {
            if ((dummy[l] -= tmp) == 0) ++l;
            if ((dummy[r] -= tmp) == 0) --r;

            if (--tmp > 0) continue;
            
            auto sum = accumulate(dummy, dummy + N, 0);
            if (sum % 2 == 0 && k != 1 || sum == 0 && k == 1) cout << k << '\n';
            else cout << "no quotation\n";
            return;
        }
    }
}

int main()
{
    while (cin >> N)
    {
        read();
        solve();
    }
}