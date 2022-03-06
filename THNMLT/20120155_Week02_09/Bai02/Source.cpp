#include<iostream>
using namespace std;

int main()
{
    char c;
    cout << "Hay nhap mot chu cai ban dau:";
    cin >> c;
    if (c >= 'a' && c <= 'z')
    {
        c = c - 32;
        cout << "Chu cai luc sau:" << c;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        c = c + 32;
        cout << "Chu cai luc sau:" << c;
    }
    system("pause");
}

