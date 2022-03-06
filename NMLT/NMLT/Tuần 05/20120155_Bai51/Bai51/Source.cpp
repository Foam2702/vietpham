#include<iostream>
using namespace std;

long long findMax(long long n)
{
	int max = 0;
	int temp = 0;
	while (n > 0)
	{
		temp = n % 10;
		if (temp >= max)
		{
			max = temp;
		}
		n /= 10;

	}
	return max;
}
int main()
{
	long long n = 0;
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n <= 0)
		{
			cout << "n phai la so nguyen duong" << endl;
		}
	} while (n <= 0);


	cout << "Chu so lon nhat cua so nguyen duong :" << findMax(n);

}