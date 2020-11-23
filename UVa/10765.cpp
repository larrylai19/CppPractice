#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

/*
reference:
https://ppt.cc/foedPx
https://ppt.cc/fxMzyx
*/

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int main()
{
    int n, m;
    int time;
    vector<int> dfsD;
    vector<int> low;
    vector<int> cnt;
    vector<vector<int>> G;
    vector<pair<int, int>> ret;

    function<void(int, int)> dfs = [&](int N, int parent)
    {
        int child = 0;

        dfsD[N] = low[N] = ++time;

        for (auto& i : G[N])
        {
            if (dfsD[i])
            {
                if (i != parent) low[N] = min(dfsD[i], low[N]);
                continue;
            }

            ++child;
            dfs(i, N);
            low[N] = min(low[i], low[N]);

            // 紀錄有幾個點將 N 視為割點
            if (low[i] >= dfsD[N] && (parent != -1 || child >= 2)) ++cnt[N];
        }
    };

    while (cin >> n >> m && (n || m))
    {
        // init
        time = 0;
        dfsD.assign(n, 0);
        low.assign(n, 0);
        cnt.assign(n, 0);
        G.assign(n, vector<int>());
        ret.clear();

        int a, b;
        while (cin >> a >> b && !(a == -1 && b == -1))
        {   // 無向圖，建雙向邊
            G[a].push_back(b);
            G[b].push_back(a);
        }

        for (int i = 0; i < n; ++i) if (!dfsD[i]) dfs(i, -1);

        // 最後要加一是因為若有一個節點將此點視為割點，則拿掉此點
        // 圖會被分為兩部分，若有 n 個，則為 n + 1
        for (int i = 0; i < n; ++i) ret.push_back({ i, cnt[i] + 1 });

        // 根據題目的要求排序 ( 值較大的在上面，若值相等則序號較小的在上面 )
        auto cmp = [](pair<int, int>& l, pair<int, int>& r)
        {
            return l.second == r.second ? l.first < r.first : l.second > r.second;
        };
        sort(begin(ret), end(ret), cmp);
        
        for (int i = 0; i < m; ++i) cout << ret[i].first << " " << ret[i].second << '\n';
        cout << '\n';
    }
}