#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    double x,A;
        cout<<"Hay nhap so thuc x =";
        cin>>x;
        cout<<"Hay nhap so nguyen duong n =";
        cin>>n;
if(n<=0,floor(n)==n)
{
       cout<<"n phai la so nguyen duong";
}   
else
{
        A=pow((pow(x,2)+1),n);
        cout<<"Gia tri cua (x^2+1)^n ="<<A;
}
return 1;
}