#include <iostream>
#include <fstream>
#include <tchar.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main()
{
	char test[20];

	cout << "Downloading file..." << endl;
	HRESULT hr = URLDownloadToFile(NULL, _T("https://www.larrysprognotes.com/DownloadTest.dat"), _T("DownloadTest.dat"), 0, NULL);
	cout << "Done!" << endl << endl;
	
	ifstream in("DownloadTest.dat", ios::binary);
	
	while (in.read((char*)&test, sizeof(test)))
		cout << test;
	cout << endl;
}