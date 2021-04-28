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

// reference: https://ppt.cc/f1uJix

const int INF = (int)1e9;
const int MXN = 555;

int rn[MXN][MXN]; // 剩餘網路
int p[MXN];
bool vis[MXN];
map<string, int> dict;
map<int, string> reDict;

int N;
int S, T; // Source, Sink

void init()
{
    CLR(rn);
    dict.clear();
    reDict.clear();
}

void read()
{
    cin >> N;

    int tmp, cnt = 0;
    string str;
    FOR(i, 1, N + 1)
    {
        cin >> tmp;
        while (tmp--)
        {
            cin >> str;
            for (auto& s : str) s = tolower(s);
            str[0] = toupper(str[0]);

            if (!dict.count(str))
            {
                dict[str] = ++cnt;
                reDict[cnt] = str;
            }

            int v = dict[str] + N;
            rn[i][v] = 1;
        }
    }

    // build edges
    T = N + dict.size() + 26 + 1;
    FOR(i, 1, N + 1) rn[S][i] = 1;
    FOR(i, N + dict.size() + 1, T) rn[i][T] = 1;

    for (auto& [s, u] : dict)
    {
        int v = s[0] - 'A' + N + dict.size() + 1;
        rn[u + N][v] = 1;
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

            FOR(v, 0, T + 1)
            {
                if (vis[v] || rn[u][v] <= 0) continue;

                q.push(v);
                vis[v] = true;
                p[v] = u;
            }
        }

        if (!vis[T]) break;
        mf += augment(p[T], T, INF);
    }

    return mf;
}

void solve()
{
    static int C = 0;
    vector<string> ret;

    maxiumFlow();

    FOR(i, N + dict.size() + 1, T) FOR(j, N + 1, N + (int)dict.size() + 1)
    {
        if (rn[j][i] == 0 && rn[i][j])
        {
            ret.push_back(reDict[j - N]);
            break;
        }
    }
    sort(ret.begin(), ret.end());

    cout << "Case #" << ++C << ":\n";
    for (auto& s : ret) cout << s << '\n';
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