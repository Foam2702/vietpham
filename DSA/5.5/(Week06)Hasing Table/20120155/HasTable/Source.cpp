#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
struct CongTy 
{
	string ten_Cong_ty;
	string ma_So_Thue;
	string dia_Chi;
};
CongTy convertstringToCongTy(string s) 
{
	CongTy congty;
	stringstream ss;
	ss << s;
	getline(ss, congty.ten_Cong_ty, '|');
	getline(ss, congty.ma_So_Thue, '|');
	getline(ss, congty.dia_Chi);
	return congty;
}
vector<CongTy> ReadFile(string Filename) 
{
	ifstream in;
	in.open(Filename);
	vector<CongTy> comp;
	if (!in.is_open()) 
	{
		cout << "FILE NOT EXIST" << endl;
	}
	else 
	{
		string temp;
		while (!in.eof()) 
		{
			getline(in, temp);
			comp.push_back(convertstringToCongTy(temp));
		}
	}
	return comp;
}
int main() 
{	
	string filename = "mst.txt";
	vector<CongTy> congty = ReadFile(filename);
}