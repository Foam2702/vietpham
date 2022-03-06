#include<iostream>
#include<vector>
using namespace std;

int daysoHailstone(int n)
{	
	cout << n << " ";
	if (n == 1)
	{
		return n;
	}
	else if (n % 2 == 0)
	{	
		return daysoHailstone(n / 2);
	}
	else if(n % 2 != 0)	
	{
		return daysoHailstone((3 * n) + 1);
	}
	
}

int main()
{
	int x,n;
	cin >> n;
	x=daysoHailstone(n);
	return 0;
	
}
 

