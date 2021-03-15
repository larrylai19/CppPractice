#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int Case;
int T;
int n;
int mxLIS;
int mxLDS;
int heights[10000];
int weights[10000];
int LIS[10000];
int LDS[10000];

void read()
{
    mxLIS = mxLDS = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> heights[i];
    for (int i = 0; i < n; ++i) cin >> weights[i], LIS[i] = LDS[i] = weights[i];
}

void solve()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
			// 若 i 能接在 j 後面 ( LIS )
            if (heights[i] > heights[j]) LIS[i] = max(LIS[j] + weights[i], LIS[i]);
			// 若 i 能接在 j 後面 ( LDS )
            if (heights[i] < heights[j]) LDS[i] = max(LDS[j] + weights[i], LDS[i]);
        }
        mxLIS = max(LIS[i], mxLIS);
        mxLDS = max(LDS[i], mxLDS);
    }

    cout << "Case " << ++Case << ". ";
    if (mxLIS >= mxLDS) cout << "Increasing (" << mxLIS << "). Decreasing (" << mxLDS << ").\n";
    else cout << "Decreasing (" << mxLDS << "). Increasing (" << mxLIS << ").\n";
}

int main()
{
    cin >> T;
    while (T--)
    {
        read();
        solve();
    }
}