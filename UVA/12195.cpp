#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    while ((cin >> input) && input != "*")
    {
        int ans = 0, time = 0;

        for (size_t i = 1; i < input.size(); ++i)
        {
            switch (input[i])
            {
            case 'W':
                time += 64;
                break;
            case 'H':
                time += 32;
                break;
            case 'Q':
                time += 16;
                break;
            case 'E':
                time += 8;
                break;
            case 'S':
                time += 4;
                break;
            case 'T':
                time += 2;
                break;
            case 'X':
                time += 1;
                break;
            default:
                if (time == 64)
                    ++ans;
                time = 0;
                break;
            }
        }

        cout << ans << endl;
    }
}