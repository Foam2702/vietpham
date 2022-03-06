#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double a, b, c, x1, x2, delta;
    cout << "Phuong trinh bac 2 ax^2+bx+c=0" << endl;
    cout << "Hay nhap gia tri cua a =";
    cin >> a;
    cout << "Hay nhap gia tri cua b=";
    cin >> b;
    cout << "Hay nhap gia tri cua c=";
    cin >> c;
    if (a == 0)
        cout << "Gia tri cua a phai khac 0";
    else
    {
        delta = b * b - 4 * a * c;
        if (delta > 0)
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet x1 = " << x1 << " va x2 = " << x2;
        }
        else if (delta == 0)
        {
            if (b == 0)
            {
                b = 0 / (2 * a);
                cout << "Phuong trinh co nghiem kep x1=x2=" << b;
            }
            else
            {
                x1 = x2 = -b / (2 * a);
                cout << "Phuong trinh co nghiem kep x1=x2=" << x1;
            }
        }
        else if (delta < 0)
        {
            cout << "Phuong trinh vo nghiem";
        }

    }
    system("pause");
}

