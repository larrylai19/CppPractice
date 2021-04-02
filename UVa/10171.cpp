#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int INF = (int)1e9;

int m;
int G1[26][26];
int G2[26][26];

void init()
{
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j) G1[i][j] = G2[i][j] = INF;
        G1[i][i] = G2[i][i] = 0;
    }
}

void read()
{
    int w;
    char a, b, u, v;
    while (m--)
    {
        cin >> a >> b >> u >> v >> w;
        auto ptr = (a == 'Y') ? G1 : G2;
        
        u -= 'A', v -= 'A';
        ptr[u][v] = min(w, ptr[u][v]);
        if (b == 'B') ptr[v][u] = min(w, ptr[v][u]);
    }
}

void FloydWarshall()
{
    for (int k = 0; k < 26; ++k)
    {
        for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j)
        {
            G1[i][j] = min(G1[i][k] + G1[k][j], G1[i][j]);
            G2[i][j] = min(G2[i][k] + G2[k][j], G2[i][j]);
        }
    }
}

void solve()
{
    char a, b;
    cin >> a >> b;
    a -= 'A', b -= 'A';

    int mn = INF;
    for (int k = 0; k < 26; ++k) mn = min(G1[a][k] + G2[b][k], mn);

    if (mn == INF) { cout << "You will never meet.\n"; return; }
    
    cout << mn;
    for (int k = 0; k < 26; ++k) if (G1[a][k] + G2[b][k] == mn)
        cout << ' ' << char(k + 'A');
    cout << '\n';
}

int main()
{
    while (cin >> m && m)
    {
        init();
        read();
        FloydWarshall();
        solve();
    }
}