#include<iostream>
using namespace std;

int main()
{
float R,Chuvi,Dientich;
const float Pi=3.14159;
    cout<<"Nhap ban kinh hinh tron =";
    cin >>R;
if(R>0)
{
    Chuvi   =2*Pi*R;
    Dientich=Pi*R*R;
    cout<<"Chu vi hinh tron ="   <<Chuvi<<endl;
    cout<<"Dien tich hinh tron ="<<Dientich;
}
else
{
    cout<<"Gia tri cua ban kinh phai lon hon 0";
}
return 1;
}