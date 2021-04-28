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

// reference: https://ppt.cc/fXrOUx

const int INF = (int)1e9;
const int MXN = 530;

int rn[MXN][MXN];
int l[MXN];

// source: 0, sink: P + S + 1
int P, S, C, m;
int source = 0, sink;

void init()
{
    CLR(rn);
}

void read()
{
    cin >> P >> S >> C >> m;
    sink = P + S + 1;

    int u, v;
    while (m--)
    {
        cin >> u >> v;
        rn[u][P + v] = 1;
    }

    // build edges
    FOR(i, 1, P + 1) rn[source][i] = 1;
    FOR(i, 1, S + 1) rn[i + P][sink] = C;
}

bool dinicBFS()
{
    CLR(l);

    queue<int> q;
    q.push(source);
    l[source] = 1;

    while (!q.empty())
    {
        int u = QPOP(q);

        FOR(v, 1, sink + 1)
        {
            if (l[v] || !rn[u][v]) continue;
            l[v] = l[u] + 1;
            q.push(v);
        }
    }

    return l[sink];
}

int dinicDFS(int u, int cp)
{
    if (u == sink) return cp;
    
    int tmp = cp;

    for (int v = 1; v <= sink && tmp; ++v)
    {
        if (l[v] != l[u] + 1 || !rn[u][v]) continue;
        int bottleNeck = dinicDFS(v, min(rn[u][v], tmp));
        rn[u][v] -= bottleNeck;
        rn[v][u] += bottleNeck;
        tmp -= bottleNeck;
    }

    return cp - tmp;
}

// Dinic
int maxiumFlow()
{
    int mf = 0;
    while (dinicBFS()) mf += dinicDFS(source, INF);
    return mf;
}

void solve()
{
    cout << maxiumFlow() << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        init();
        read();
        solve();
    }
}