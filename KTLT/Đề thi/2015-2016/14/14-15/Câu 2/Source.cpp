#include<iostream>
#include<string>
#include<fstream>
using namespace std; 

void converTexttoBinary(string Text, string Binary)
{
	ifstream in;
	ofstream out;
	in.open(Text,ios_base::in);
	out.open(Binary, ios_base::out);

	if (!in.is_open())
	{
		cout << "\nERROR";
		system("pause");
		return;
	}
	
	short dong, cot;
	in >> dong >> cot;
	
	out.write((char*)&dong, sizeof(dong));
	out.write((char*)&cot, sizeof(cot));
	
	int value=0;

	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			
			in >> value;
			out.write((char*)&value, sizeof(value));

		}
	}


	in.close();
	out.close();
}

void converBinarytoText(string Binary, string Text)
{
	ifstream in;
	ofstream out;
	in.open(Binary, ios_base::in);
	out.open(Text, ios_base::out);
	if (!in.is_open())
	{
		cout << "\nERROR";
		system("pause");
		return;
	}

	short dong, cot;
	in.read((char*)&dong, sizeof(dong));
	in.read((char*)&cot, sizeof(cot));
	out << dong << " " << cot << endl;

	int newvalue;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{	
			in.read((char*)&newvalue, sizeof(newvalue));
			out << newvalue << " ";
		}
		out << endl;
	}
	in.close();
	out.close();
}

int main()
{
	string text = "text.txt";
	string binary = "bin.dat";
	string sectext = "sec.txt";
	converTexttoBinary(text, binary);
	converBinarytoText(binary, sectext);
	return 0;
}