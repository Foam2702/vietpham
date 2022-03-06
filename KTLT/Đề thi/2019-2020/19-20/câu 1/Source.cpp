#include<iostream>
#include<cmath>
using namespace std;

void extract(int* A, int N, int X, int*& B, int& M)
{	
	int* C = new int[N];
	M = 0;
	int compare =abs( X - A[0]);
	for (int i = 1; i < N; i++)
	{
		int temp =abs(X - A[i]);
		if (temp < compare)
		{	
			compare = temp;
			
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		int temp2 = abs(X - A[i]);
		if (temp2 == compare)
		{
			B[M] = A[i];
			M++;

		}
	}
	for (int j = 0; j < M; j++)
	{
		cout << B[j] << endl;
	}
	cout <<"M="<< M;
	
}
int main()
{
	int n,x,m;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Nhap phan tu muon so sanh:"; cin >> x;
	extract(a, n, x, b, m);
	delete []a;
	delete []b;

}