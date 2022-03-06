#include<iostream>
#include<math.h>
using namespace std;

int main()
{
float R,S;
const float Pi=3.14159;
    cout<<"Hay nhap dien tich hinh tron =";
    cin>>S;
if (S<=0)
{
    cout<<"Gia tri dien tich phai lon hon 0";
}
else
{
    R=sqrt(S/Pi);
    cout<<"Ban kinh hinh tron ="<<R<<endl;

}
return 1;
}