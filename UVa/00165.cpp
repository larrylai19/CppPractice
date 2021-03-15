#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fFRd4x

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int h, k;
int mx;
int stamp[10] = { 1 };
int ans[10];
int maxVal[10];
bool check[180];

void init()
{
    mx = 0;
    maxVal[0] = h;
}

int getVal()
{
    int i = 0, cnt = 0;
    while (check[++i]) ++cnt;
    return cnt;
}

void dfs(int n, int idx, int sum)
{
    check[sum] = true;
    if (n == h) return; // 若已選了 h 張郵票
    for (int i = 0; i <= idx; ++i) dfs(n + 1, idx, sum + stamp[i]);
}

// 模擬最多 k 種面額的郵票組合
void execute(int idx = 1)
{
    if (idx == k)
    {
        if (maxVal[idx - 1] > mx)
        {
            mx = maxVal[idx - 1];
            memcpy(ans, stamp, sizeof(stamp));
        }
        return;
    }

    for (int i = stamp[idx - 1] + 1; i <= maxVal[idx - 1] + 1; ++i)
    {
        stamp[idx] = i;
        memset(check, 0, sizeof(check));
        dfs(0, idx, 0);
        maxVal[idx] = getVal();
        execute(idx + 1);
    }
}

void solve()
{
    for (int i = 0; i < k; ++i) cout << setw(3) << ans[i];
    cout << " ->" << setw(3) << mx << '\n';
}

int main()
{
    while (cin >> h >> k && (h || k))
    {
        init();
        execute();
        solve();
    }
}