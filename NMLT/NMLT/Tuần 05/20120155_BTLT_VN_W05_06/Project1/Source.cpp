#include<iostream>
using namespace std;

void XetcacTamgiac(int a, int b, int c)
{
	if (a < b + c && b < a + c && c < a + b)
	{
		if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
			cout << "Tam giac vuong";
		else if (a == b && b == c)
			cout << "Tam giac deu";
		else if (a == b || a == c || b == c)
			cout << "Tam giac can";
		else if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b)
			cout << "Tam giac tu";
		else
			cout << "Tam giac nhon";
	}
	else
	{
		cout << "Khong phai tam giac";
	}

}
int main()
{
	int a = 0, b = 0, c = 0;
	do
	{
		cout << "Nhap canh a:"; cin >> a;

		cout << "Nhap canh b:"; cin >> b;

		cout << "Nhap canh c:"; cin >> c;

		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "Cac canh phai lon hon 0 " << endl;
		}


	} while (a <= 0 || b <= 0 || c <= 0);
	XetcacTamgiac(a, b, c);
	
}