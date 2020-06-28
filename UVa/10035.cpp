#include <iostream>

using namespace std;

int main()
{
    string num1, num2;

    while (cin >> num1 >> num2)
    {
        if (num1 == "0" && num2 == "0")
            break;

        int carry = 0, carryNum = 0;

        while (num1.size() > 0 && num2.size() > 0)
        {
            carry += (num1.back() - '0') + (num2.back() - '0');
            if (carry >= 10)
                ++carryNum;
            num1.pop_back(), num2.pop_back();
            carry /= 10;
        }

        if (num1.size() > 0)
        {
            if (carry + (num1.back() - '0') >= 10)
                ++carryNum;
        }
        else if (num2.size() > 0)
        {
            if (carry + (num2.back() - '0') >= 10)
                ++carryNum;
        }

        switch (carryNum)
        {
        case 0:
            cout << "No carry operation." << endl;
            break;
        case 1:
            cout << "1 carry operation." << endl;
            break;
        default:
            cout << carryNum << " carry operations." << endl;
            break;
        }
    }
}