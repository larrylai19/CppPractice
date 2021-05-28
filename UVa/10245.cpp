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

// reference: https://ppt.cc/f4Uwtx

const int INF = (int)1e9;
const int MXN = 10000;

struct Point
{
    double x;
    double y;
};

int N;
Point P[MXN];

double dist(const Point& l, const Point& r)
{
    return sqrt(pow(r.x - l.x, 2) + pow(r.y - l.y, 2));
}

void read()
{
    FOR(i, 0, N) cin >> P[i].x >> P[i].y;
}

void solve()
{
    // sweep line
    sort(P, P + N, [](Point& l, Point& r) { return l.x < r.x; });

    double d = 1e4;
    FOR(i, 0, N) FOR(j, i + 1, N)
    {
        if (P[i].x + d < P[j].x) break; // 若區域內沒有點則不需要再判斷
        d = min(dist(P[i], P[j]), d);
    }

    if (d == 1e4) cout << "INFINITY\n";
    else cout << setprecision(4) << fixed << d << '\n';
}

int main()
{
    while (cin >> N && N)
    {
        read();
        solve();
    }
}