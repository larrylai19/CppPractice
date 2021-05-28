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

const int INF = (int)1e9;
const int MXN = 100000;

struct Point
{
    double x;
    double y;
    double d; // 與第一個點的距離
};

Point P[MXN];

string str;
int N;
int top; // 凸包頂點數

// 兩點間的距離
double dist(const Point& l, const Point& r)
{
    return sqrt(pow(l.x - r.x, 2) + pow(l.y - r.y, 2));
}

double crossProduct(const Point& o, const Point& a, const Point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

// 選出最下面的點，若有相同 y 的點則選擇 x 較小的那個
bool cmp1(const Point& l, const Point& r)
{
    return l.y == r.y ? l.x < r.x : l.y < r.y;
}

// 極角排序，cp > 0: ol -> or 逆時針
bool cmp2(const Point& l, const Point& r)
{
    auto cp = crossProduct(P[0], l, r);
    return cp == 0 ? l.d < r.d : cp > 0;
}

void read()
{
    N = 0;
    char c;
    stringstream ss(str);
    while (ss >> c >> P[N].x >> c >> P[N].y >> c) ++N;
}

// Convex Hull
void GrahamScan()
{
    // 找出第一個點，並將其他點依照極角排序
    sort(P, P + N, cmp1);
    FOR(i, 1, N) P[i].d = dist(P[0], P[i]);
    sort(P + 1, P + N, cmp2);

    // 找凸包
    top = 1;
    P[N++] = P[0];
    FOR(i, 2, N)
    {
        while (top > 0 && crossProduct(P[top - 1], P[top], P[i]) <= 0) --top;
        P[++top] = P[i];
    }
}

void solve()
{
    FOR(i, 0, top + 1)
    {
        if (i) cout << ' ';
        cout << '(' << P[i].x << ',' << P[i].y << ')';
    }
    cout << '\n';
}

int main()
{
    while (getline(cin, str))
    {
        read();
        GrahamScan();
        solve();
    }
}