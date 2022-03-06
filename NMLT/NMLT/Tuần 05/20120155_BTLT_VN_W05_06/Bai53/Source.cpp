#include<iostream>
using namespace std;

int CountMax(int n)
{	
	int temp=0, max=0, count=0;

	temp = n;
	while (temp != 0)
	{
		if (max < temp % 10)
		{
			max = temp % 10;
		}
		temp /= 10;
	}
	temp = n;
	while (temp != 0)
	{
		if (temp % 10 == max)
		{
			count++;
		}
		temp /= 10;
	}
	return count;
}
int main()
{
	int n;
	do {
		cout << "Nhap n:"; cin >> n;
		if (n <= 0)
		{
			cout << "n phai la so nguyen duong" << endl;
		}
	} while (n <= 0);

	int count = CountMax(n);
	cout << "So luong chu so lon nhat la :" << count;
	
}