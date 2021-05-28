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

// reference: https://ppt.cc/fqcIxx

const int INF = (int)1e9;
const int MXN = 102;

struct Point
{
    double x;
    double y;
    double d; // 與第一個點的距離
};

Point P[MXN];

int N;
int top; // 凸包頂點數
double l;

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
    cin >> l >> N;
    FOR(i, 0, N) cin >> P[i].x >> P[i].y;
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
    FOR(i, 2, N)
    {
        while (top > 0 && crossProduct(P[top - 1], P[top], P[i]) <= 0) --top;
        P[++top] = P[i];
    }
    P[++top] = P[0];
}

void solve()
{
    double sum = 0;

    if (N > 2)
    {
        GrahamScan();
        FOR(i, 0, top) sum += dist(P[i], P[i + 1]);
    }
    else if (N == 2) sum = dist(P[0], P[1]) * 2;

    cout << setprecision(5) << fixed << max(sum, l) << '\n';
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