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

// reference: https://ppt.cc/fKhjIx

const int INF = (int)1e9;
const int MXN = 2005;

int S, T;
int rn[MXN][MXN];
int l[MXN];

int Y, X, P;
int tot;
int d[] = { 1, 0, -1, 0, 1 };

void init()
{
    CLR(rn);
}

void read()
{
    tot = Y * X;
    T = 2 * tot + 1;

    char c;
    FOR(y, 0, Y) FOR(x, 0, X)
    {
        int u = X * y + x + 1;
        cin >> c;
        
        switch (c)
        {
        case '*': // 有人
            rn[u][u + tot] = 1;
            rn[S][u] = 1;
            break;

        case '.': // 薄冰
            rn[u][u + tot] = 1;
            break;

        case '@': // 厚冰
            rn[u][u + tot] = INF;
            break;

        case '#':
            rn[u][u + tot] = INF;
            rn[u + tot][T] = P;
            break;
        }

        FOR(i, 0, 4)
        {
            int dx = x + d[i];
            int dy = y + d[i + 1];
            if (dx < 0 || dx >= X || dy < 0 || dy >= Y) continue;

            int v = X * dy + dx + 1;
            rn[u + tot][v] = INF;
        }
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
    while (cin >> Y >> X >> P)
    {
        init();
        read();
        solve();
    }
}