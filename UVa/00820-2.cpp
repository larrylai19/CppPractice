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
const int MXN = 101;

int rn[MXN][MXN];
int l[MXN];

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

bool dinicBFS()
{
    CLR(l);

    queue<int> q;
    q.push(S);
    l[S] = 1;

    while (!q.empty())
    {
        int u = QPOP(q);
        
        FOR(v, 1, N + 1)
        {
            if (l[v] || !rn[u][v]) continue;
            l[v] = l[u] + 1;
            q.push(v);
        }
    }

    return l[T];
}

int dinicDFS(int u, int cp)
{
    if (u == T) return cp;

    int tmp = cp;

    for (int v = 1; v <= N && tmp; ++v)
    {
        if (l[v] != l[u] + 1 || !rn[u][v]) continue;

        int bottleNeck = dinicDFS(v, min(rn[u][v], tmp));
        rn[u][v] -= bottleNeck;
        rn[v][u] += bottleNeck;
        tmp -= bottleNeck;
    }

    return cp - tmp;
}

int maxiumFlow()
{
    int mf = 0;
    while (dinicBFS()) mf += dinicDFS(S, INF);
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