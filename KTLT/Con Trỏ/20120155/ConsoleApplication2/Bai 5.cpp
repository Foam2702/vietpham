#include"Header.h"

int main()
{
	int n, m;
	int** a = CreateArr(n, m);
	InputArr(a, n, m);
	OutputArr(a, n, m);
	FreeArr(a, n);

}