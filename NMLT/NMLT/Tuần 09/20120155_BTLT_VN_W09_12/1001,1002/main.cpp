#include"Header.h"

int main()
{
	int n = 0;
	TamGiac TG[100];
	ifstream in;
	ofstream out;
	in.open("input.txt", ios_base::in);
	if (!in.is_open())
	{
		cout << "CAN'T OPEN FILE";
	}
	else
	{
		in >> n;
		ReadFile(in, TG, n);
	}
	out.open("output.txt", ios_base::out);
	WriteFile(out, TG, n);
	
	out.close();
	in.close();

	system("pause");
}