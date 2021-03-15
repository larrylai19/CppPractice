#include <iostream>

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
    // e -> empty, f -> found, c -> cost
    int T, e, f, c, ret;
    cin >> T;
    while (T--)
    {
        cin >> e >> f >> c;
        ret = 0;
        e += f; // total empty bottles
        while (e >= c)
        {
            int bottles = e / c;
            ret += bottles;
            e = bottles + e % c;
        }
        cout << ret << '\n';
    }
}