#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/fedUBx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int INF = (int)1e9;

int C;
int n, m;
int dist[101][101];

void init()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) dist[i][j] = INF;
        dist[i][i] = 0;
    }
}

void read()
{
    cin >> n >> m;
    init();

    int u, v;
    while (m--) cin >> u >> v, dist[u][v] = dist[v][u] = 1;
}

void FloydWarshall()
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
            dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    }
}

void solve()
{
    int b, e, mx = INT_MIN;
    cin >> b >> e;

    for (int k = 0; k < n; ++k) mx = max(dist[b][k] + dist[k][e], mx);
    cout << "Case " << ++C << ": " << mx << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        read();
        FloydWarshall();
        solve();
    }
}