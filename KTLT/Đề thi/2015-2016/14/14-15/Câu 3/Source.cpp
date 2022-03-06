#include<iostream>
#include<stack>
using namespace std;

void XuatHe2(long n)
{
	if (n == 0)
	{
		return ;
	}
	 XuatHe2(n / 2);
	cout << n % 2;
	
}

void DoiHe_DungMang(long n, int he)
{
	int a[100];
	int size = 0;

	while (n != 0) // Điều kiện lặp là n phải khác 0. Nếu bằng 0 thì quá trình lặp dừng lại
	{
		a[size++] = n % he;
		n /= he; // Bước lặp
	}

	for (int i = size - 1; i >= 0; --i)
	{
		if (a[i] < 10)
			cout << a[i];
		else if (a[i] == 10)
			cout << "A";
		else if (a[i] == 11)
			cout << "B";
		else if (a[i] == 12)
			cout << "C";
		else if (a[i] == 13)
			cout << "D";
		else if (a[i] == 14)
			cout << "E";
		else if (a[i] == 15)
			cout << "F";
	}
}

void DoiHe_DungStack(long n, int he)
{
	stack<int> nganxep;
	while (n != 0)
	{
		nganxep.push(n % he);
		n /= he;
	}
	int x = 0;
	while (!nganxep.empty())
	{
		x = nganxep.top();//lấy phần tử trên cùng
		nganxep.pop();//bỏ phần tử trên cùng(vì được lấy ở trên rồi)
		if (x < 10)
		{
			cout << x;
		}
		if (x == 10)cout << "A";
		if (x == 11)cout << "B";
		if (x == 12)cout << "C";
		if (x == 13)cout << "D";
		if (x == 14)cout << "E";
		if (x == 15)cout << "F";
		
	}
}
int main()
{
	long n = 13;
	//XuatHe2(n);
	DoiHe_DungMang(250, 16);
	cout << endl;
	DoiHe_DungStack(250, 16);
	system("pause");
	return 0;
}

