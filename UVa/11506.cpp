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

const int INF = (int)1e9;
const int MXN = 102;

int S = 1, T;
int rn[MXN][MXN];
int l[MXN];

int M, W;

void init()
{
    CLR(rn);
}

void read()
{
    // 1 ~ M: out, M + 1 ~ 2M: in
    T = M * 2;

    int u, v, c;
    FOR(i, 0, M - 2) cin >> u >> c, rn[u + M][u] = rn[u][u + M] = c;

    FOR(i, 0, W) cin >> u >> v >> c, rn[u][v + M] = rn[v][u + M] = c;
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

        FOR(v, 0, T + 1)
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

    FOR(v, 0, T + 1 && tmp)
    {
        if (l[v] != l[u] + 1 || !rn[u][v]) continue;
        int bt = dinicDFS(v, min(rn[u][v], tmp));
        rn[u][v] -= bt;
        rn[v][u] += bt;
        tmp -= bt;
    }

    return cp - tmp;
}

int maximumFlow()
{
    int mf = 0;
    while (dinicBFS()) mf += dinicDFS(S, INF);
    return mf;
}

void solve()
{
    cout << maximumFlow() << '\n';
}

int main()
{
    while (cin >> M >> W && !(!M && !W))
    {
        init();
        read();
        solve();
    }
}