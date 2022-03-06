#include<iostream>
#include<fstream>
using namespace std;

struct Dinh
{
	int x = 0;
	int y = 0;
};
struct Dagiac
{	
	int sodinh;
	Dinh dinh;
};

void fReadTextFiletoBinary(string Text, string Binary)
{
	ifstream in;
	ofstream out;
	in.open(Text);
	out.open(Binary);
	if (!in.is_open())
	{
		cout << "Error";
	}

	int M;
	in >> M;
	out.write((char*)&M, sizeof(M));
	Dagiac dagiac;
	for (int i = 0; i < M; i++)
	{
		in >> dagiac.sodinh;
		out.write((char*)&dagiac.sodinh, sizeof(dagiac));
		for (int j = 0; j < dagiac.sodinh; j++)
		{
			in >> dagiac.dinh.x;
			out.write((char*)&dagiac.dinh.x, sizeof(dagiac));
			in >> dagiac.dinh.y;
			out.write((char*)&dagiac.dinh.y, sizeof(dagiac));
		}
	}

	in.close();
	out.close();
}
void fReadBinaryFiletoText(string Binary, string Text)
{
	ifstream in;
	ofstream out;
	in.open(Binary);
	out.open(Text);
	if (!in.is_open())
	{
		cout << "Error";
	}
	int N;//so luong da giac
	in.read((char*)&N, sizeof(N));
	out << N << endl;
	Dagiac newdagiac;
	for (int i = 0; i < N; i++)
	{
		in.read((char*)&newdagiac.sodinh, sizeof(newdagiac));
		out << newdagiac.sodinh << " ";
		for (int j = 0; j < newdagiac.sodinh; j++)
		{
			in.read((char*)&newdagiac.dinh.x, sizeof(newdagiac));
			out << newdagiac.dinh.x << " ";
			in.read((char*)&newdagiac.dinh.y, sizeof(newdagiac));
			out << newdagiac.dinh.y << " ";
		}
		out << endl;
	}


	in.close(); 
	out.close();

}


int main()
{
	string binary = "DAGIAC.bin";
	string text = "DAGIAC.txt";
	string sectext = "SEC.txt";
	fReadTextFiletoBinary(text, binary);
	fReadBinaryFiletoText(binary, sectext);
	return 0;
}