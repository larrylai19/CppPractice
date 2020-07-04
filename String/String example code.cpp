#include <iostream>
#include <string>

using namespace std;

void print(string& str1, string& str2)
{
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl << endl;
}

void equal(string& str1, string& str2)
{
	cout << "str1 == str2: ";
	if (str1 == str2)
		cout << "True" << endl << endl;
	else
		cout << "False" << endl << endl;
}

int main()
{
	string str1, str2;

	str1 = "string 1";
	str2 = "string 2";
	print(str1, str2);
	// str1: string 1
	// str2: string 2

	str1 += str2;
	print(str1, str2);
	// str1: string 1string 2
	// str2: string 2

	cout << "在 str1 內尋找 str2: " << str1.find(str2) << endl << endl;

	equal(str1, str2);
	// str1 == str2: False
	str1 = str2;
	equal(str1, str2);
	// str1 == str2: True

	str1 = "strings";
	cout << "str1: " << str1 << endl << endl;

	cout << "在 str1 內從頭尋找字符為 s 的位置: " << str1.find_first_of("s") << endl;
	// 在 str1 內從頭尋找字符為 s 的位置: 0
	cout << "在 str1 內從尾尋找字符為 s 的位置: " << str1.find_last_of("s") << endl << endl;
	// 在 str1 內從尾尋找字符為 s 的位置: 6
	cout << "在 str1 內從頭尋找字符不為 s 的位置: " << str1.find_first_not_of("s") << endl;
	// 在 str1 內從頭尋找字符不為 s 的位置: 1
	cout << "在 str1 內從尾尋找字符不為 s 的位置: " << str1.find_last_not_of("s") << endl << endl;
	// 在 str1 內從尾尋找字符不為 s 的位置: 5
}