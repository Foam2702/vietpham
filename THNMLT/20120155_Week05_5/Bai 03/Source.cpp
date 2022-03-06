#include"Header.h"

int giaithua(int n)
{	
	int giaithua = 1;
	if (n == 0)
		return 1;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			giaithua *= i;
		}
	}
	return giaithua;
}

int Tohop(int n, int k)
{
	return (giaithua(n)) / (giaithua(k) * giaithua(n - k));
}
void tamGiacpascal(int n)
{	
	
	for (int i = 0; i <= n; i++)
	{
		for (int j = n; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << Tohop(i, j)<< " ";
		}
		cout << endl;
	}
}