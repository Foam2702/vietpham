#include<iostream>
#include<fstream>
#include<string>
using namespace std;


struct duongtron
{
	unsigned short X=0;
	unsigned short Y=0;
	unsigned short R=0;
};

struct danhsach
{
	duongtron* Dsdt=NULL;
	int n=0;
};

void convertTexttoBinary(string Text, string Binary)
{
	ifstream in;
	ofstream out;
	in.open(Text);
	out.open(Binary);
	if (!in.is_open())
	{
		cout << "ERROR TEXT FILE"<<endl;
	}
	
	if (!out.is_open())
	{
		cout << "ERROR BINARY FILE" << endl;
	}

	unsigned short N;
	char ch;
	in >> N;
	out.write((char*)&N, sizeof(N));

	danhsach ds1;
	ds1.n = N;
	
	ds1.Dsdt = new duongtron[ds1.n];

	
	for (int i = 0; i < ds1.n; i++)
	{
		in >> ds1.Dsdt[i].X>>ds1.Dsdt[i].Y>>ds1.Dsdt[i].R;
		out.write((char*)&ds1.Dsdt[i], sizeof(duongtron));
		//cout<< ds1.Dsdt[i].X << ds1.Dsdt[i].Y << ds1.Dsdt[i].R<<endl;
	}

	in.close();
	out.close();
}
void convertBinarytoText(string Binary, string Text)
{
	ifstream in;
	ofstream out;
	in.open(Binary);
	if (!in.is_open())
	{
		cout << "ERROR BINARY FILE";
	}
	out.open(Text);
	if (!out.is_open())
	{
		cout << "ERROR TEXT FILE";
	}

	unsigned short N;
	in.read((char*)&N, sizeof(N));

	out << N <<endl;

	danhsach ds;
	ds.n = N;
	ds.Dsdt = new duongtron[ds.n];
	for (int i = 0; i < ds.n; i++)
	{
		in.read((char*)&ds.Dsdt[i],sizeof(duongtron));
		out << ds.Dsdt[i].X << ";" << ds.Dsdt[i].Y << ";" << ds.Dsdt[i].R << endl;
	}

	in.close();
	out.close();
}

int main()
{
	string binary = "bin.dat";
	string text = "text.txt";
	string sectext = "sectext.txt";
	convertTexttoBinary(text, binary);
	convertBinarytoText(binary, sectext);
	return 0;
}