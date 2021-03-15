#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

string process(string& str)
{
    string ret;
    for (auto& ch : str) if (isalnum(ch) && !isalpha(ch)) ret += ch;
    return ret;
}

int main()
{
    int n, m, x = 0;
    while ((cin >> n).ignore() && n)
    {
        string str, ans, output;

        // 讀取正確答案，並加入換行
        for (int i = 0; i < n; ++i)
        {
            getline(cin, str);
            if (i) ans += '\n';
            ans += str;
        }

        // 讀取需要比對的答案，並加入換行
        (cin >> m).ignore();
        for (int i = 0; i < m; ++i)
        {
            getline(cin, str);
            if (i) output += '\n';
            output += str;
        }

        cout << "Run #" << ++x << ": ";

        // 先檢查是否 AC
        if (ans == output) cout << "Accepted\n";
        else if (process(ans) == process(output)) cout << "Presentation Error\n";
        else cout << "Wrong Answer\n";
    }
}