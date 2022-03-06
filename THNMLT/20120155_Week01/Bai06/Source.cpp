#include<iostream>
using namespace std;

int main()
{
    double a, Dientich, Chuvi;
    do {
        cout << "Nhap canh cua hinh vuong = ";
        cin >> a;
        if (a <= 0)
        {
            cout << "Canh hinh vuong phai lon hon 0" << endl;
        }
    } while (a <= 0);
    
    Dientich = a * a;
    Chuvi = 4 * a;
    cout << "Dien tich cua hinh vuong = " << Dientich << endl;
    cout << "Chu vi cua hinh vuong = " << Chuvi;
    
    
    return 1;
}