#include<iostream>
using namespace std;

int main()
{
    int a, b, Tong, Hieu, Tich;
    float Thuong;

    cout << "Hay nhap so nguyen a =";
    cin >> a;
    cout << "Hay nhap so nguyen b =";
    cin >> b;
    Tong = a + b;
    Hieu = a - b;
    Tich = a * b;
    Thuong =(float) a / b;
    cout << "Tong 2 so nguyen =" << Tong << endl;
    cout << "Hieu 2 so nguyen =" << Hieu << endl;
    cout << "Tich 2 so nguyen =" << Tich << endl;
    cout << "Thuong 2 so nguyen =" << Thuong << endl;
    return 1;
}