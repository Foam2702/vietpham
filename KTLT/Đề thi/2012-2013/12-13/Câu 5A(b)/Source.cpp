#include<iostream>
#include<fstream>
using namespace std;

void convertTexttoBinary(string text, string binary)
{
	ifstream in;
	ofstream out;
	in.open(text,ios_base::in);
	out.open(binary,ios_base::out);
	if (!in.is_open())
	{
		cout << "ERROR" << endl;
	}
	float value;
	int count = 0;

	while (!in.eof())
	{	
		in >> value;
		out.write((char*)&value, sizeof(value));
		count++;
	}

	in.close();
	out.close();
}

void convertBinarytoText(string secbinary, string thirdtext)
{
	ifstream in;
	ofstream out;
	in.open(secbinary,ios_base::in);
	out.open(thirdtext,ios_base::out);
	if (!in.is_open())
	{
		cout << "ERROR";
	}
	
	short count = 0;
	in.read((char*)&count, sizeof(count));
	out << count<<endl;

	float temp=0;
	while (in.read((char*)&temp, sizeof(temp)))
	{
		out << temp<< " ";
	}
	
	in.close();
	out.close();
}
void convertBinarytoBinary(string binary, string secbinary)
{	
	ifstream in;
	ofstream out;
	in.open(binary, ios_base::in);
	if (!in.is_open())
	{
		cout << "ERROR";
	}
	out.open(secbinary, ios_base::out);

	float newdata;
	short count = 0;

	while (in.read((char*)&newdata, sizeof(newdata)))
	{
		count++;
	}
	out.write((char*)&count, sizeof(count));
	in.close();

	in.open(binary, ios_base::in);
	while (in.read((char*)&newdata, sizeof(newdata)))
	{	
		out.write((char*)&newdata, sizeof(newdata));
		
	
	}
	
	in.close();
	out.close();

}

int main()
{
	string text = "text.txt";
	string binary = "binary.dat";
	string sectext = "sec.txt";
	string thirdtext = "third.txt";
	string secbinary = "secbinary.dat";
	convertTexttoBinary(text, binary);
	convertBinarytoBinary(binary, secbinary);
	convertBinarytoText(secbinary, thirdtext);
	return 0;
}