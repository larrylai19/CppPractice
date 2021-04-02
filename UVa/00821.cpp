#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/f6R74x

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int INF = (int)1e9;

int C;
int dist[101][101];
int N;
int u, v;

void init()
{
    N = 1;
    for (int i = 1; i < 101; ++i)
    {
        for (int j = 1; j < 101; ++j) dist[i][j] = INF;
        dist[i][i] = 0;
    }
}

void read()
{
    do
    {
        dist[u][v] = 1;
        N = (max(max(u, v), N));
    } while (cin >> u >> v && (u || v));
}

void FloydWarshall()
{
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
            dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    }

    double sum = 0;
    int cnt = 0;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
        if (dist[i][j] < INF && dist[i][j]) sum += dist[i][j], ++cnt;

    cout << "Case " << ++C << ": average length between pages = ";
    cout << setprecision(3) << fixed << sum / cnt << " clicks\n";
}

int main()
{
    while (cin >> u >> v && (u || v))
    {
        init();
        read();
        FloydWarshall();
    }
}