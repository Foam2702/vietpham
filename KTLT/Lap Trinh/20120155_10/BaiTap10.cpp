#include<iostream>
using namespace std;

int main()
{
float C,S;    
    cout<<"Mot hinh chu nhat co chieu dai bang 1.5 chieu rong"<<endl;
    cout<<"Hay nhap chu vi hinh chu nhat =";
    cin>>C;
if(C<=0)
{
    cout<<"Gia tri chu vi phai lon hon 0";
}    
else
{
    S=1.5*((C*C)/25);
    cout<<"Dien tich hinh chu nhat ="<<S;
}
return 1;
}