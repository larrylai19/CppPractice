#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void build(unordered_map< char, char>& table); // 建表

int main()
{
    string data;
    unordered_map< char, char> dict;
    build(dict);

    while (getline(cin, data))
    {
        for (auto& i : data)
            cout << dict[i];
        cout << endl;
    }
}

void build(unordered_map< char, char>& table)
{
    table['1'] = '`', table['2'] = '1', table['3'] = '2', table['4'] = '3';
    table['5'] = '4', table['6'] = '5', table['7'] = '6', table['8'] = '7';
    table['9'] = '8', table['0'] = '9', table['-'] = '0', table['='] = '-';
    table['W'] = 'Q', table['E'] = 'W', table['R'] = 'E', table['T'] = 'R';
    table['Y'] = 'T', table['U'] = 'Y', table['I'] = 'U', table['O'] = 'I';
    table['P'] = 'O', table['['] = 'P', table[']'] = '[', table[92] = ']';
    table['S'] = 'A', table['D'] = 'S', table['F'] = 'D', table['G'] = 'F';
    table['H'] = 'G', table['J'] = 'H', table['K'] = 'J', table['L'] = 'K';
    table[';'] = 'L', table[39] = ';', table['X'] = 'Z', table['C'] = 'X';
    table['V'] = 'C', table['B'] = 'V', table['N'] = 'B', table['M'] = 'N';
    table[','] = 'M', table['.'] = ',', table['/'] = '.', table[32] = 32;
}