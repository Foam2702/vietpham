#include<iostream>
using namespace std;

int Mutiply(int x, int y)
{
	if (x == 0)
	{
		return 0;
	}
	else if (x % 2 == 0)
	{
		return Mutiply((x >> 1) , (y << 1));
	}
	else if (x % 2 != 0)
	{

		return Mutiply((x >> 1) , (y << 1))+y;
	}
}
	

int main()
{
	int x = 0, y = 0,mutiply=0;
	cin >> x >> y;
	mutiply=Mutiply(x, y);
	cout << mutiply;
}