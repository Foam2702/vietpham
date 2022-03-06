#include"Header.h"

int main()
{
	double a[100];
	int n;
	Input(a, n);
	cout << "Mang truoc khi sap xep: " << endl;
	Output(a, n);
	sapxeptang(a, n);
	cout << "Mang sau khi sap xep: " << endl;
	Output(a, n);
	system("pause");
}