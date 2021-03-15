#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fxmaAx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int maxN = (int)1e6 + 1;

int N;
int ans[maxN];

void preProcessing()
{
    for (int i = 1; i < maxN; ++i) for (int j = i; j < maxN; j += i) ++ans[j];

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