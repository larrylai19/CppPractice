#include <bits/stdc++.h>

using namespace std;

/*
reference:
    https://ppt.cc/fJv50x
    Floyd-Warshall Algorithm:
        https://ppt.cc/fstMux
        https://ppt.cc/fsQm1x
*/

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int inf = (int)1e9;

int N;
int a, b;
int G1[101][101];
int G2[101][101];

void init()
{
    fill(G1[0], G1[0] + 101 * 101, inf);
    fill(G2[0], G2[0] + 101 * 101, inf);
}

void readGraph(int (*G)[101])
{
    int tmp;
    string str;
    stringstream ss;
    for (int i = 1; i <= N; ++i)
    {
        getline(cin, str);
        ss.clear();
        ss.str(str);
        ss >> tmp;
        while (ss >> tmp) G[i][tmp] = 1;
    }
}

void FloydWarshall()
{
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
        {
            G1[i][j] = min(G1[i][j], G1[i][k] + G1[k][j]);
            G2[i][j] = min(G2[i][j], G2[i][k] + G2[k][j]);
        }
    }
}

bool solve()
{
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
        if (i != j && G2[i][j] > G1[i][j] * a + b) return false;
    return true;
}

int main()
{
    while ((cin >> N).ignore() && N)
    {
        init();

        readGraph(G1);
        readGraph(G2);
        cin >> a >> b;

        FloydWarshall();

        if (solve()) cout << "Yes\n";
        else cout << "No\n";
    }
}