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
    string str;
    while (getline(cin, str))
    {
        for (auto& ch : str) ch -= 7;
        cout << str << '\n';
    }
}