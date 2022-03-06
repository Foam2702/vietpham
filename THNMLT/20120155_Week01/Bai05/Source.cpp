#include<iostream>
using namespace std;

int main()
{
    double rong, dai, Dientich, Chuvi;
   
    do {
        cout << "Nhap chieu rong hinh chu nhat = ";
        cin >> rong;
        cout << "Nhap chieu dai hinh chu nhat = ";
        cin >> dai;
        if (rong <= 0 || dai <= 0)
        {
            cout << "Chieu rong va chieu dai phai lon hon 0" << endl;
        }
    } while (rong <= 0 || dai <= 0);
    
    Dientich = rong * dai;
    Chuvi = (dai + rong) * 2;
    cout << "Dien tich hinh chu nhat = " << Dientich << endl;
    cout << "Chu vi hinh chu nhat = " << Chuvi;
    
    
    return 1;
}