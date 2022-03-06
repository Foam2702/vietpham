#include<iostream>
using namespace std;

long chuyenNhiphan(int n)
{
    long bin = 0;
    int r, temp = 1;

    while (n != 0)
    {
        r = n % 2;
        n = n / 2;
        bin = bin + r * temp;
        temp = temp * 10;
    }
    return bin;
}
int main()
{
    int n;
    do {
        cout << "Nhap n:"; cin >> n;
        if (n <= -255 || n >= 255)
        {
            cout << "Nhap lai n";
        }

    } while (n <= -255 || n >= 255);

    cout << chuyenNhiphan(n);
    system("pause");
}