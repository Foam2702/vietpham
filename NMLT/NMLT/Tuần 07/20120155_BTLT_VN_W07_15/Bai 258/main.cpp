#include"Header.h"

int main()
{
	int a[100],n;
	Input(a, n);
	cout << "Mang truoc khi sap xep: " << endl;
	Output(a, n);
	nguyentotang(a, n);
	cout << "Mang sau khi sap xep: " << endl;
	Output(a, n);
	system("pause");
}