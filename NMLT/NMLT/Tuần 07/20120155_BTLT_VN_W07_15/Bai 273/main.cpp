#include"Header.h"

int main()
{
	double a[100];
	int n;
	Input(a, n);
	cout << "Mang truoc khi xoa" << endl;
	Output(a, n);
	xoaam(a, n);
	cout << "Mang sau khi xoa: " << endl;
	Output(a, n);
	system("pause");
}