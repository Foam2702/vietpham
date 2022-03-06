#include<iostream>
using namespace std;

int f[100];

int TinhFn(unsigned int n)
{
	if (n == 0) return f[n]=3;
	else if (n == 1) return f[n]=4;
	else if (n == 2) return f[n]=5;
	else
	{
		int f1 = TinhFn((n - 1));
		int f2 = TinhFn((n - 2));
		int f3 = TinhFn((n - 3));
		f[n] = 3*f1 + 4*f2 + 5*f3;
	}
	return f[n];
}

int TinhFnKoDeQuy(int n)

{
	int  F0 = 3, F1 = 4, F2 = 5,Fn=0;

	if (n == 0)
		return F0;
	else if (n == 1)
		return F1;
	else if(n == 2)
		return F2;
	
	
	for (int i = 3; i <= n; i++)
	{
		Fn = 3 * F2 + 4 * F1 + 5 * F0;
		F0 = F1;
		F1 = F2;
		F2 = Fn;

	}
	return Fn;
	
}

int timMax(int M)
{
	int i = 0;
	TinhFnKoDeQuy(i);
	while (TinhFnKoDeQuy(i) < M||TinhFnKoDeQuy(i)==M)
	{
		i++;
	}
	return i;
}

int main()
{
	
	
	/*int n; cin >> n;
	int value=TinhFn(n);
	int value1 = TinhFnKoDeQuy(n);
	cout <<value<<endl<<value1<<endl;*/
	int M; cin >> M;
	int max;
	max = timMax(M);
	cout << max;


}