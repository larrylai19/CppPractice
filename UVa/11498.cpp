#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int main()
{
    int T, N, M, x, y;

    while (cin >> T && T)
    {
        cin >> N >> M;

        while (T--)
        {
            cin >> x >> y;

            if (x == N || y == M) cout << "divisa\n";
            else if (x > N && y > M) cout << "NE\n";
            else if (x > N && y < M) cout << "SE\n";
            else if (x < N && y > M) cout << "NO\n";
            else cout << "SO\n";
        }
    }
}