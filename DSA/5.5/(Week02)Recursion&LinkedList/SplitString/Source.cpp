#include<iostream>
#include<string>
using namespace std;

void Split(string str)
{
	string word = "";
	for (auto x : str)
	{
		if (x == ',')
		{
			cout << word << endl;
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	cout << word << endl;
}

int main()
{
	string str = "BD1200001,a van nguyen,4.0,5.0,,,,4.25,7.0,7.75,,,2.0,N1,BinhDinh";
	Split(str);
	return 0;
}