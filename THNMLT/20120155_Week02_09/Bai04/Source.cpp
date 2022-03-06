#include<iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cout << "Nhap so nguyen a =";
    cin >> a;
    cout << "Nhap so nguyen b =";
    cin >> b;
    cout << "Nhap so nguyen c =";
    cin >> c;
    cout << "Nhap so nguyen d =";
    cin >> d;
    if (a - b > 0)
        swap(a, b);
    else if (a - c > 0)
        swap(a, c);
    else if (a - d > 0)
        swap(a, d);
    else if (b - c > 0)
        swap(b, c);
    else if (b - d > 0)
        swap(b, d);
    else if (c - d > 0)
        swap(c, d);
    cout << "Thu tu tang dan cua 4 so nguyen la : " << endl;
    cout << a << " " << b << " " << c << " " << d;
    system("pause");

}
