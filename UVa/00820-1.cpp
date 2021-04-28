#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define CLR(c) memset(c, 0, sizeof(c))

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

template <typename T>
T QPOP(queue<T>& q)
{
    T tmp = q.front();
    q.pop();
    return tmp;
}

// reference: https://ppt.cc/fv1Gvx

const int INF = (int)1e9;
const int MXN = 101;

int rn[MXN][MXN];
int p[MXN];
bool vis[MXN];

int N, S, T, C; // S: Source, T: Sink

void init()
{
    CLR(rn);
}

void read()
{
    int u, v, w;
    cin >> S >> T >> C;
    while (C--)
    {
        cin >> u >> v >> w;
        rn[u][v] += w;
        rn[v][u] += w;
    }
}

int augment(int u, int v, int bottleNeck)
{
    if (v == S) return bottleNeck;
    bottleNeck = augment(p[u], u, min(rn[u][v], bottleNeck));
    rn[u][v] -= bottleNeck;
    rn[v][u] += bottleNeck;
    return bottleNeck;
}

// Edmonds-Karp
int maxiumFlow()
{
    int mf = 0;

    while (true)
    {
        CLR(vis);

        queue<int> q;
        q.push(S);
        vis[S] = true;

        while (!q.empty() && !vis[T])
        {
            int u = QPOP(q);

            FOR(v, 1, N + 1)
            {
                if (vis[v] || !rn[u][v]) continue;

                q.push(v);
                vis[v] = true;
                p[v] = u;
            }
        }

        if (!vis[T]) break; // no path
        mf += augment(p[T], T, INF);
    }

    return mf;
}

void solve()
{
    static int C = 0;
    cout << "Network " << ++C << '\n';
    cout << "The bandwidth is " << maxiumFlow() << ".\n\n";
}

int main()
{
    while (cin >> N && N)
    {
        init();
        read();
        solve();
    }
}