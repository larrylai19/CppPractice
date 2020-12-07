#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <queue>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
};

// data
int N;
int energy[101];
int dist[101];
vector<int> G[101];   // 正向圖
vector<int> re[101];  // 反向圖
unordered_set<int> s; // 可以連到終點的點

void init()
{
    s.clear();
    fill(dist, dist + 101, 0);
    fill(G, G + 101, vector<int>());
    fill(re, re + 101, vector<int>());
}

// 從終點往回走 ( 反向圖 )，找出可以到達終點的點
void dfs(int u)
{
    s.insert(u);
    for (auto& v : re[u]) if (!s.count(v)) dfs(v);
}

bool bellman()
{
    // 從 1 開始
    dist[1] = 100;

    // 若不存在正環，則做 n - 1 次後 dist 會儲存 1 到每個點的最大能量走法
    for (int i = 0; i < N - 1; ++i) for (int u = 1; u <= N; ++u) for (auto& v : G[u])
    {
        if (dist[u]) dist[v] = max(dist[u] + energy[v], dist[v]);
    }

    for (int u = 1; u <= N; ++u) for (auto& v : G[u])
    {
        // 若 v 還能變大表示有正環，可以重複走直到能量無限，
        // 所以如果 v 能到達終點，表示一定能走到終點
        if (dist[u] && dist[v] < dist[u] + energy[v])
        {
            if (s.count(v)) return true;
            dist[v] = dist[u] + energy[v];
        }
    }

    return dist[N];
}

int main()
{
    while (cin >> N && N != -1)
    {
        init();

        for (int i = 1; i <= N; ++i)
        {
            int j, tmp;
            cin >> tmp >> j;
            energy[i] = tmp;
            while (j--) cin >> tmp, G[i].push_back(tmp), re[tmp].push_back(i);
        }

        // 找出可以走到終點的點
        dfs(N);

        if (bellman()) cout << "winnable\n";
        else cout << "hopeless\n";
    }
}