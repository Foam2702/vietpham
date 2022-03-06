#include<iostream>
using namespace std;

double tinhS(int n)
{	
	
	if (n == 1)
		return 1;
	else
	{	
		
		return (double) 1 / n + tinhS(n - 1);
		
	}
} 
int main()
{
	int n; cin >> n;
	double sum = tinhS(n);
	cout << sum;
	
	return 0;

}