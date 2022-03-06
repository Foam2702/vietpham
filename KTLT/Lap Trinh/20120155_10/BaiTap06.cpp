#include<iostream>
using namespace std;

int main()
{
float a,Dientich,Chuvi;
    cout<<"Nhap canh cua hinh vuong =";
    cin >>a;
if(a>0)
    {
        Dientich=a*a;
        Chuvi=4*a;
    cout<<"Dien tich cua hinh vuong ="<<Dientich<<endl;
    cout<<"Chu vi cua hinh vuong ="   <<Chuvi;
    }
else
    {
    cout<<"Gia tri canh hinh vuong phai lon hon 0";
    }
return 1;    
}