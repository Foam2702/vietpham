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
    if (a > b)
        swap(a, b);
    else if (a > c)
        swap(a, c);
    else if (a > d)
        swap(a, d);
    else if (b > c)
        swap(b, c);
    else if (b > d)
        swap(b, d);
    else if (c > d)
        swap(c, d);
    cout << "So co gia tri nho nhat la " << a;
    system("pause");

}
