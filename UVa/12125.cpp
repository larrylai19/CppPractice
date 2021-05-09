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

struct Point
{
    int x;
    int y;
    int n;
    int m;

    void read() { cin >> x >> y >> n >> m; }
};

// reference: https://ppt.cc/fHi3ax

const int INF = (int)1e9;
const int MXN = 205;

int S, T;
int rn[MXN][MXN];
int l[MXN];

int N;
double D;
int tot;
Point p[MXN];

double dist(const Point& l, const Point& r)
{
    return sqrt(pow(l.x - r.x, 2) + pow(l.y - r.y, 2));
}

void read()
{
    cin >> N >> D;

    tot = 0;
    T = N * 2 + 1;
    FOR(i, 1, N + 1) p[i].read(), tot += p[i].n;
}

void build(int u)
{
    CLR(rn);

    FOR(i, 1, N + 1)
    {
        rn[S][i] = p[i].n;

        // 冰塊的跳出限制
        if (i == u) rn[u][u + N] = INF;
        else rn[i][i + N] = p[i].m;

        FOR(j, i + 1, N + 1)
        {
            if (dist(p[i], p[j]) > D) continue;
            rn[i + N][j] = INF;
            rn[j + N][i] = INF;
        }
    }

    rn[u + N][T] = INF;
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
    int cnt = 0;

    FOR(i, 1, N + 1)
    {
        build(i);
        if (maximumFlow() == tot)
        {
            if (cnt++) cout << ' ';
            cout << i - 1;
        }
    }

    if (!cnt) cout << "-1\n";
    else cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        read();
        solve();
    }
}