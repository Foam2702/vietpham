#include<iostream>
using namespace std;

int X(int n)//đệ quy
{
	if (n == 1||n==2)
		return 1;
	else
	{
		return X(n - 1) + (n - 1)*X(n - 2);
	}
}

int TinhXn(int n) //không dùng đệ quy
{
	int f1 = 1, f2 = 1;
	int fn = 0;
	for (int i = 3; i <= n; i++)
	{
		fn = f2 + (i - 1) * f1;
		f1 = f2;
		f2 = fn;
	}
	return fn;
}


int main()
{
	int n; cin >> n;
	cout<<X(n)<<endl<<TinhXn(n);
	return 0;
}