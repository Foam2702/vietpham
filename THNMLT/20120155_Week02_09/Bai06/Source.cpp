#include<iostream>
using namespace std;

int main()
{

    double km, a, b, c, d;
    cout << "Hay nhap so km =";
    cin >> km;
    
    if (km < 1)
    {
        a = km * 15000;
        cout << "Tong tien :" << a << "d";
    }

    else if (km >= 2 && km <= 5)
    {
        b = 1 * 15000 + ((km - 1) * 13500);
        cout << "Tong tien: " << b << "d";
    }

    else if (km >= 6 && km <= 120)
    {
        c = (1 * 15000) + ((4) * 13500) + ((km - 5) * 11000);
        cout << "Tong tien: " << c << "d";
    }

    else if (km > 120)
    {
        d = ((1 * 15000) + (4 * 13500) + ((km - 5) * 11000)) - (((1 * 15000) + (4 * 13500) + (km - 5) * 11000) * 10 / 100);
        cout << "Tong tien: " << d << "d";

    }
    system("pause");
}
