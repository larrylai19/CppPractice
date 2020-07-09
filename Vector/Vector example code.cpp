#include <iostream>
#include <vector>
using namespace std;

void output(vector< int >& Vec) // 印出 Vector 內的所有元素及 Vector 的 size
{
    cout << "Vector 內的元素: ";
    for (size_t i = 0; i < Vec.size(); ++i)
        cout << Vec[i] << " ";
    cout << endl << "Vector 的 size : ";
    cout << Vec.size();
    if (Vec.empty())
        cout << endl << "Vector.empty() : True";
    else
        cout << endl << "Vector.empty() : False";
    cout << endl << endl;
}

int main()
{
    vector<int> Vec;

    Vec.push_back(2);
    Vec.push_back(1);
    output(Vec);
    // 2 1
    // 2
    // False

    Vec.insert(Vec.begin(), 3);
    output(Vec);
    // 3 2 1
    // 3
    // False

    Vec.insert(Vec.begin(), 2, 4);
    output(Vec);
    // 4 4 3 2 1
    // 5
    // False

    Vec.erase(Vec.begin() + 2);
    output(Vec);
    // 4 4 2 1
    // 4
    // False

    Vec.erase(Vec.begin(), Vec.begin() + 2);
    output(Vec);
    // 2 1
    // 2
    // False

    Vec.clear();
    output(Vec);
    // 
    // 0
    // True

    for (int i = 1; i < 10; ++i)
        Vec.push_back(i);
    output(Vec);
    // 1 2 3 4 5 6 7 8 9
    // 9
    // False

    cout << "Vector.front(): "<< Vec.front() << endl;
    // 1
    cout << "Vector.back(): " << Vec.back() << endl;
    // 9
    cout << "Vector[1]: " << Vec[1] << endl;
    // 2
    cout << "Vector.at(1): " << Vec.at(1) << endl << endl;
    // 2

    Vec.resize(5);
    output(Vec);
    // 1 2 3 4 5
    // 5
    // False

    Vec.resize(9);
    output(Vec);
    // 1 2 3 4 5 0 0 0 0
    // 9
    // False
    
    for (vector< int >::iterator it = Vec.begin(); it != Vec.end(); ++it)
        cout << *it << " ";
    cout << endl << endl;
    // 1 2 3 4 5 0 0 0 0

    for (vector< int >::reverse_iterator it = Vec.rbegin(); it != Vec.rend(); ++it)
        cout << *it << " ";
    cout << endl << endl;
    // 0 0 0 0 5 4 3 2 1
}