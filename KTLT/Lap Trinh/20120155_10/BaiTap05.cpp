#include<iostream>
using namespace std;

int main()
{
double rong,dai,Dientich,Chuvi;
    cout<<"Nhap chieu rong hinh chu nhat =";
    cin >>rong;
    cout<<"Nhap chieu dai hinh chu nhat =";
    cin >>dai;
if (rong>0 && dai>0)
    {
        Dientich=rong*dai;
        Chuvi=(dai+rong)*2;
        cout<<"Dien tich hinh chu nhat ="<<Dientich<<endl;
        cout<<"Chu vi hinh chu nhat ="   <<Chuvi;
    }
           
        
else
    {
        cout<<"Gia tri chieu dai va chieu rong phai lon hon 0";
    }
    
       


return 1;
}