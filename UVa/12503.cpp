#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T, p, temp, moveNum;
    string move;
    vector< int > moveTemp;

    cin >> T;

    while (T--)
    {
        p = 0;

        cin >> moveNum;
        moveTemp.clear();

        while (moveNum--)
        {
            cin >> move;

            switch (move[0])
            {
            case 'L':
                --p;
                moveTemp.push_back(-1);
                break;
            case 'R':
                ++p;
                moveTemp.push_back(1);
                break;
            case 'S':
                cin >> move >> temp;
                p += moveTemp[temp - 1];
                moveTemp.push_back(moveTemp[temp - 1]);
                break;
            }
        }
        cout << p << endl;
    }
}