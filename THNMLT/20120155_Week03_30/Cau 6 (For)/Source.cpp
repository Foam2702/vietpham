#include<iostream>
using namespace std;

int FindMin()
{
	int sum = 0;
	int n = 0;
	for(int i = 1 ; ; i++)
	{
		n++;
		sum += n;
		
		if (sum > 1000)
			break;
	}
	return n;
}
int main()
{
	int n = FindMin();
	cout << n;
	system("pause");
}