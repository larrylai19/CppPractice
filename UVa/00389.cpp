#include <bits/stdc++.h>

using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

string orgin;
int n;
int m;
int Dec;
list<char> ret;

void split()
{
    stringstream ss(orgin);
    ss >> orgin >> n >> m;
}

void cvtToDec()
{
    for (auto& ch : orgin)
        Dec = Dec * n + (isalpha(ch) ? ch - 'A' + 10 : ch - '0');
}

void cvtToAns()
{
    ret.clear();

    while (Dec)
    {
        int tmp = Dec % m;
        ret.push_front(tmp < 10 ? tmp + '0' : tmp - 10 + 'A');
        Dec /= m;
    }

    if (ret.empty()) ret.push_back('0');
}

void print()
{
    if (ret.size() > 7) { cout << "  ERROR\n"; return; }

    while (ret.size() < 7) ret.push_front(' ');
    for (auto& ch : ret) cout << ch;
    cout << '\n';
}

int main()
{
    while (getline(cin, orgin))
    {
        split();
        cvtToDec();
        cvtToAns();
        print();
    }
}