#include"Header.h"

int main()
{
	ifstream in;
	ofstream out;
	ToaDo a,b;
	in.open("input.txt", ios_base::in);
	if (!in.is_open())
	{
		cout<<"CAN'T OPEN FILE";
	}
	else
	{
		ReadFile(in, a,b);
	}
	out.open("output.txt", ios_base::out);
	WriteFile(out, a,b);

	
	in.close();
	out.close();
	system("pause");
}