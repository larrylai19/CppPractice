#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int u, v;
unordered_map<int, vector<int>> G;
unordered_map<int, int> inDegree;
unordered_set<int> visited;

void init()
{
    G.clear();
    inDegree.clear();
    visited.clear();
}

void readGraph()
{
    while (!(!u && !v))
    {
        G[u].push_back(v);
        inDegree[u] += 0;
        ++inDegree[v];
        cin >> u >> v;
    }
}

// 如果有環則回傳 false
bool dfs(int u)
{
    visited.insert(u);
    for (auto& v : G[u])
    {
        if (visited.count(v)) return false; // 有環
        if (!dfs(v)) return false;
    }
    return true;
}

bool solve()
{
    // 沒有節點也是樹
    if (inDegree.empty()) return true;

    for (auto& [u, deg] : inDegree)
    {
        if (deg) continue;
        if (!dfs(u)) return false;
        break;
    }

    // 檢查是否有節點還沒有遍歷過
    for (auto& [u, _] : inDegree)
        if (!visited.count(u)) return false;
    return true;
}

int main()
{
    int Case = 0;
    while (cin >> u >> v && !(u == -1 && v == -1))
    {
        init();
        readGraph();
        
        cout << "Case " << ++Case << " is ";
        if (solve()) cout << "a tree.\n";
        else cout << "not a tree.\n";
    }
}