#include<iostream>
using namespace std;

void Hoanvi(string str, int i, int n)
{
    int j;
    if (i == n)
        cout << str << endl;
    else
    {
        for (j = i; j <= n; j++)
        {
            swap(str[i], str[j]);
            Hoanvi(str, i + 1, n);
            swap(str[i], str[j]);
        }
    }
}

int main()
{
    string str = "ABCD";
    Hoanvi(str, 0, 3);
   
}
