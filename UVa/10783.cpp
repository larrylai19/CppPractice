#include <iostream>

using namespace std;

int main()
{
    int a, b, T, casenum = 1;

    cin >> T;

    while (T--)
    {
        int ans = 0;

        cin >> a >> b;

        for (int i = a; i <= b; ++i)
            if (i % 2 == 1)
                ans += i;

        cout << "Case " << casenum << ": " << ans << endl;
        ++casenum;
    }
}