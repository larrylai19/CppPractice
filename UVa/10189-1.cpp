#include <iostream>
#include <vector>

using namespace std;

int result[102][102] = {};

void clearResult(int n, int m)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            result[i][j] = 0;
}

void addResult(int n, int m)
{
    ++result[n - 1][m - 1];
    ++result[n][m - 1];
    ++result[n + 1][m - 1];

    ++result[n - 1][m];
    ++result[n + 1][m];

    ++result[n - 1][m + 1];
    ++result[n][m + 1];
    ++result[n + 1][m + 1];

    result[n][m] = -100;
}

void outputResult(int n, int m)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            if (result[i][j] < 0)
                cout << "*";
            else
                cout << result[i][j];
        cout << endl << endl;
    }
}

int main()
{
    int n, m, casenum = 1;
    size_t pos;
    string map;

    while (cin >> n >> m)
    {
        if (!n && !m)
            break;

        clearResult(n + 2, m + 2);

        for (int i = 0; i < n; ++i)
        {
            cin >> map;

            while ((pos = map.find('*')) != string::npos)
            {
                map[pos] = '.';
                addResult(i + 1, pos + 1);
            }
        }

        cout << "Field #" << casenum << ":" << endl;
        outputResult(n, m);
        ++casenum;
    }
}