#include<iostream>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) 
{	
	bool check = false;
	if (v1 > v2)
	{
		if ((x2 - x1) % (v1 - v2) == 0)
			check = true; 
		if (check == true)
			return "YES";
		else
			return "NO";
	}
	else
		return "NO";
}

int main()
{
	int x1, v1, x2, v2;
	cin >> x1 >> v1 >> x2 >> v2;
	string s = kangaroo(x1, v1, x2, v2);
	cout << s;
	return 0;
}