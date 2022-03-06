#include"Header.h"
int main()
{
	int n;
	int *a = CreateArr(n);
	InputArr(a, n);
	OutputArr(a, n);
	CountSNT(a, n);
	delete[]a;
	return 0;
}