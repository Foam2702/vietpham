#include<iostream>
#include<string>
using namespace std;

const int MaxSize = 1024;

int main()
{	
	char Buff[MaxSize];
	int i = 0;
	while (Buff[i] != '.')
	{
		cin >> Buff[i];
		i++;
	}
	cout << Buff;
	system("pause");
	return 0;
}