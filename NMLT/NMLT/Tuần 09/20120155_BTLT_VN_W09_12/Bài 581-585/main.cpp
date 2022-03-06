#include"Header.h"

int main()
{
	ifstream in;
	ofstream out;
	TamGiac TG;

	in.open("input.txt", ios_base::in);
	if (!in.is_open())
	{
		cout << "CAN'T OPEN FILE";
	}
	else
	{
		ReadFile(in, TG);
	}
	out.open("output.txt", ios_base::out);
	WriteFile(out, TG);

	in.close();
	out.close();
	system("pause");
}