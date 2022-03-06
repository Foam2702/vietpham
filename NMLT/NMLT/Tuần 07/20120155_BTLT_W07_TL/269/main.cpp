#include"Header.h"
int main()
{
	int a[100];
	int n, x;
	
	Input(a, n);
	
	cout << "Nhap x:"; cin >> x;

	thembaotoan(a, n, x);
	Output(a, n);

}