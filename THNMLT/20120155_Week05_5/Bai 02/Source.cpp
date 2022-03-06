#include"Header.h"

void Input(int& a, int& b, int& c, int& d)
{   
    do
    {
        cout << "Nhap tu phan so thu nhat: ";
        cin >> a;
        cout << "Nhap mau phan so thu nhat ";
        cin >> b;
        cout << "Nhap tu phan so thu hai: ";
        cin >> c;
        cout << "Nhap mau phan so thu hai ";
        cin >> d;
        if (b == 0 || d == 0)
        {
            cout << "Mau so phai khac 0"<<endl;
        }
    } while (b == 0 || d == 0);
}


int UCLN(int a, int b)
{
    int temp=0;
    while (a!=b) 
    {
        if (a > b)
            a = a - b;
        else if (b > a)
            b = b - a;
    }
    return a;
}

void ToiGianPhanSo(int a, int b)
{
    int temp = UCLN(a, b);
    a /= temp;
    b /= temp;
    cout << "Ket qua: " << a << "/" << b << endl;
}

void TongHaiPhanSo(int a, int b, int c, int d)
{
    int temp1 = a * d + c * b;
    int temp2 = b * d;
    int temp = UCLN(temp1, temp2);
    temp1 /= temp;
    temp2 /= temp;
    cout << "Ket qua: " << temp1 << "/" << temp2 << endl;
}

void TichHaiPhanSo(int a, int b, int c, int d)
{
    int temp1 = a * c;
    int temp2 = b * d;
    int temp = UCLN(temp1, temp2);
    temp1 /= temp;
    temp2 /= temp;
    cout << "Ket qua: " << temp1 << "/" << temp2 << endl;
}



