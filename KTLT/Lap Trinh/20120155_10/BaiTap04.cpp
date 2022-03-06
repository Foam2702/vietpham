#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
float x,A;
    cout<<"Nhap so thuc x =";
    cin>>x;
    A=(3*x*x*x)-(2*x*x);
    cout<<fixed<<setprecision(2);
    cout<<"Gia tri bieu thuc A ="<<A<<endl;
    
return 1;
}