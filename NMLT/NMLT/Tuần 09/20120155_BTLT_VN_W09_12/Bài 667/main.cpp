#include"Header.h"

int main()
{	
	ifstream in;
	ofstream out;
	Tinh mang_tinh[100];
	int n=0;
	
	in.open("input.txt", ios_base::in);
	if (!in.is_open())
	{
		cout << "CAN'T OPEN FILE";
	}
	else
	{
		in >> n;
		ReadFile(in, mang_tinh, n);
	}
	out.open("output.txt", ios_base::out);
	WriteFile(out, mang_tinh,n);
	in.close();
	out.close();
	system("pause");
}