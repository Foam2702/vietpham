#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct SinhVien
{
	string Hoten;
	string Maso;
	string NamSinh;
	string Lophoc;
	double DiemTB=0;
};

struct Danhsach
{
	SinhVien* dssv;
	int n;
};



void textToBinary(char* textFile, char* binFile)
{
	ifstream in;
	ofstream out;
	int count = 0;
	in.open(textFile);
	if (in.is_open())
	{
		in.close();
	}
	in.open(textFile, ios_base::in);

	if (!in.is_open())
	{
		cout << "CANT OPEN TEXT FILE";
		system("pause");
		return;
	}
	
	while (!in.eof())
	{
		string soluong;
		getline(in, soluong);
		count++;
	}//con trỏ chỉ vị đang ở cuối file

	Danhsach ds;
	ds.n = count;
	ds.dssv = new SinhVien[ds.n];
	in.seekg(0, 0);//đưa con trỏ chỉ vị về đầu file
	for (int i = 0; i < ds.n; i++)
	{
		getline(in, ds.dssv[i].Maso, '-');	//đọc tới '-' thì con trỏ sẽ dừng và nhảy qua '-'
		getline(in, ds.dssv[i].Hoten, '-');
		getline(in, ds.dssv[i].NamSinh, '-');
		getline(in, ds.dssv[i].Lophoc, '-');
		in >> ds.dssv[i].DiemTB;
	}
	
	in.close();

	out.open(binFile,ios_base::out);
	if (!out.is_open())
	{
		cout << "CANT OPEN BINARY FILE";
		system("pause");
		return;
	}
	for (int i = 0; i < ds.n; i++)
	{
		out.write((char*)&ds.dssv[i], sizeof(SinhVien));
	}
	delete[]ds.dssv;
	out.close();	

}

void binaryToText(char* binFile, char* textFile)
{
	
	ifstream in;
	ofstream out;
	int count=0;
	in.open(binFile);
	if (in.is_open())
	{
		in.close();
	}
	in.open(binFile, ios_base::in);
	out.open(textFile, ios_base::out);

	if (!out.is_open()) {
		cout << "cant open text file";
		system("pause");
		return;
	}
	if (!in.is_open())
	{
		cout << "CANT OPEN BINARY FILE";
		system("pause");
		return;
	}
	Danhsach ds1;
	while (!in.eof())
	{
		string soluong;
		getline(in, soluong);
		count++;
	}//con trỏ chỉ vị đang ở cuối file

	in.seekg(0, 0);
	ds1.n = count;
	ds1.dssv=new SinhVien[ds1.n] ;
	

	for (int i = 0; i < ds1.n; i++)
	{
		in.read((char*)&ds1.dssv[i], sizeof(SinhVien));
		out << ds1.dssv[i].Maso << '-' << ds1.dssv[i].Hoten << '-' << ds1.dssv[i].NamSinh << '-' << ds1.dssv[i].Lophoc << '-' << ds1.dssv[i].DiemTB ;
	}
	
	in.close();
	out.close();
	
}

int main()
{
	char text[] ="text.txt";
	char bin[]	= "bin.dat";
	char sectext[] = "sectext.txt";
	textToBinary(text, bin);
	binaryToText(bin, sectext);

	return 0;

}