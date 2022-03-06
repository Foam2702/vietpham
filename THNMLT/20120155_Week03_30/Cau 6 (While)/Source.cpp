#include<iostream>
using namespace std;

int FindMin()
{
	int sum = 0;
	int n = 0;
	while (sum <= 1000)
	{
		n++;
		sum += n;
		
	}
	return n;
}
int main()
{
	int n = FindMin();
	cout << n;
	system("pause");
}