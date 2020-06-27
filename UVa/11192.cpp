#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int groupNum, groupSize;
    string data, output;

    while (cin >> groupNum)
    {
        if (!groupNum)
            break;

        cin >> data;

        groupSize = data.size() / groupNum;

        while (data.size() > 0)
        {
            reverse(data.begin(), data.begin() + groupSize);
            output.assign(data.begin(), data.begin() + groupSize);
            data.erase(0, groupSize);

            cout << output;
        }

        cout << endl;
    }
}