#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

#define encryptTimes 2

void readFile(vector< string >& data);                      // 讀取 data.txt
void produceCode(vector< int >& code);                      // 產生加密的數字
void saveCode(vector< string >& data, vector< int >& code); // 轉換
void convert(vector< string >& data, vector< int >& code);  // 將加密的數字轉換並存在第一行

int main()
{
    int choice;
    string temp;
    vector< int > code;
    vector< string > data;

    cout << "Welcome! Input 1 to encrypt, 2 to decrypt: ";
    cin >> choice;

    if (choice == 1)
    {
        readFile(data);                    // 讀取 data.txt
        produceCode(code);                 // 產生加密的數字
        convert(data, code);               // 轉換
        saveCode(data, code);              // 將加密的數字轉換並存在第一行

        ofstream outFile("encrypted.txt"); // 輸出
        for (auto& i : data)
            outFile << i << endl;
        cout << endl << "encrypt completed." << endl;
    }
    else if (choice == 2)
    {
        readFile(data);                    // 讀取 data.txt

        string readcode = data[0];         // 第一行為加密的數字
        data.erase(data.begin());          // 刪除掉第一行
        for (auto& i : readcode)           // 將第一行轉換
            code.push_back((i ^ 9) - 'a');

        convert(data, code);               // 轉換
        ofstream outFile("decrypted.txt"); // 輸出
        for (auto& i : data)
            outFile << i << endl;
        cout << endl << "decrypt completed." << endl;
    }
}

void readFile(vector< string >& data)
{
    string temp;
    ifstream inFile("data.txt");
    if (!inFile)
    {
        cout << endl << "There is no file." << endl;
        exit(0);
    }
    while (getline(inFile, temp))
        data.push_back(temp);
}

void produceCode(vector< int >& code)
{
    srand((unsigned)time(NULL));
    int codetemp;
    while (code.size() < encryptTimes)
    {
        codetemp = rand() % 10;
        auto it = find(code.begin(), code.end(), codetemp);
        if (it == code.end())
            code.push_back(codetemp);
    }
}

void saveCode(vector< string >& data, vector< int >& code)
{
    string savecode;
    for (auto& i : code)
        savecode.push_back(('a' + i) ^ 9);
    data.insert(data.begin(), savecode);
}

void convert(vector< string >& data, vector< int >& code)
{
    for (auto& i : data)
        for (auto& j : i)
            for (auto& k : code)
                if (j != 32)
                    j ^= k;
}