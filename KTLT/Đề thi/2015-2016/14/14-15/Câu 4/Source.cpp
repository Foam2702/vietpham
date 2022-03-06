#include<iostream>
using namespace std;

int countSolution(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int Pn=0, P1 = 1, P2 = 2;
	for (int i = 3; i <= n; i++)
	{
		Pn = P1 + P2;
		P1 = P2;
		P2 = Pn;
	}
	return Pn;
}
int De_Quy(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	else
	{
		return De_Quy(n - 1) + De_Quy(n - 2);
	}
}

int main()
{
	int n; cin >> n;
	int solu = countSolution(n);
	cout << solu;
	int solu2 = De_Quy(n);
	cout << endl << solu2;
	return 0;
}

