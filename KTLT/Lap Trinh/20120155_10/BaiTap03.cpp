#include<iostream>
using namespace std;

int main()
{
char c;
    cout<<"Nhap vao 1 ki tu :";
    cin>>c;
    cout<<"Ma ASCII cua ki tu :";
    cout<<static_cast<int>(c);
return 0;
}