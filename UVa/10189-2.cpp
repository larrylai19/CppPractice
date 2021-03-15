#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/f01ivx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int n, m;
char field[102][102];

void init()
{
    memset(field, '0', sizeof(field));
}

void Fill(int y, int x)
{
    for (int i = -1; i <= 1; ++i) for (int j = -1; j <= 1; ++j)
        if (field[y + i][x + j] != '*') ++field[y + i][x + j];
}

void solve()
{
    char c;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j)
    {
        cin >> c;
        if (c == '*') field[i][j] = '*', Fill(i, j);
    }
}

void print()
{
    static int Case = 0;
    if (Case) cout << '\n';
    cout << "Field #" << ++Case << ":\n";

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j) cout << field[i][j];
        cout << '\n';
    }
}

int main()
{
    while (cin >> n >> m && !(!n && !m))
    {
        init();
        solve();
        print();
    }
}