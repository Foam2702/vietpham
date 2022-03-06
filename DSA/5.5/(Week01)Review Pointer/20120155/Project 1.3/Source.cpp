#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

struct thiSinh
{
	string id, hovaTen,ghichu, tinh;;
	float toan = 0, van = 0, vatLy = 0, hoaHoc = 0, sinhHoc = 0,
		lichSu = 0, diaLy = 0, giaduccongDan = 0, KHTN = 0, KHXH = 0, ngoaiNgu = 0, diemtong = 0;
	
};

thiSinh Split(string &str)
{	
	string thisinh[15];// 1 thí sinh có 16 thông tin 
	string word = "";
	thiSinh ts;
	int count = 0;
	for (auto x : str)
	{
		if (x == ',')
		{
			if (word == "")
			{
				thisinh[count] = "0";
			}
			else
				thisinh[count] = word;
			count++;
			word = "";
		}
		else
			word = word + x;
	}

	ts.tinh = word;
	ts.id = thisinh[0];
	ts.hovaTen = thisinh[1];
	ts.toan = stof(thisinh[2]);//string -> float
	ts.van = stof(thisinh[3]);
	ts.vatLy = stof(thisinh[4]);
	ts.hoaHoc = stof(thisinh[5]);
	ts.sinhHoc = stof(thisinh[6]);
	ts.lichSu = stof(thisinh[7]);
	ts.diaLy = stof(thisinh[8]);
	ts.giaduccongDan = stof(thisinh[9]);
	ts.KHTN = ts.vatLy + ts.hoaHoc + ts.sinhHoc;
	ts.KHXH = ts.lichSu + ts.diaLy + ts.giaduccongDan;
	ts.ngoaiNgu = stof(thisinh[12]);
	ts.ghichu = thisinh[13];
	return ts;

}

vector<thiSinh> docDanhSachThiSinh(string tenFile)
{
	ifstream in;
	in.open(tenFile);
	if (!in.is_open())
	{
		cout << "CANT OPEN THE FILE";
	}
	vector<thiSinh> dsts;
	thiSinh thisinh;
	string str,dongdau;
	
	int count = 0;
	//đếm số dòng
	while (!in.eof())
	{
		string soluong;
		getline(in, soluong);
		count++;
	}
	// đọc dòng đầu
	in.seekg(0, 0);
	getline(in, dongdau);
	count--;
	//đọc từng thí sinh
	for (int i = 0; i < count; i++)
	{
		getline(in, str);
		thisinh=Split(str);
		dsts.push_back(thisinh);
		
	}	
	return dsts;
	in.close();
}

void daoNguocTenThiSinh(vector<thiSinh>& dsts)
{	
	int sizevector = dsts.size();
	int count = 0;
	int countword = 0;
	vector<char> hoten;
	for (int i = 0; i < sizevector; i++)
	{
		for (int j = dsts[i].hovaTen.length()-1; j >= 0; j--)
		{	
			count++;
			if (j == 0)
			{
				for (int k = j; k < count + j; k++)
				{
					hoten.push_back(dsts[i].hovaTen[k]);
					
				}
				hoten.push_back(dsts[i].hovaTen[0]);
				for (int l = 0; l < hoten.size(); l++)
				{
					dsts[i].hovaTen[l] = hoten[l];

				}
				hoten.clear();
				count = 0;
				
			}
			else if (dsts[i].hovaTen[j - 1] == ' ')
			{
				for (int k = j; k < count+j; k++)
				{
					hoten.push_back(dsts[i].hovaTen[k]);
					countword++;
					
				}
				j--;
				count = 0;
				hoten.push_back(' ');
			}
		}
	}
}

void vietHoaTenThiSinh(vector<thiSinh>& dsts)
{
	
	for (int i = 0; i < dsts.size(); i++)
	{
		if (dsts[i].hovaTen[0] >= 'a' && dsts[i].hovaTen[0] <= 'z')
		{
			dsts[i].hovaTen[0] -= 32;
		}
	}
	for (int i = 0; i < dsts.size(); i++)
	{
		for (int j = dsts[i].hovaTen.length()-1; j >=1 ; j--)
		{
			if (dsts[i].hovaTen[j - 1] == ' ')
			{	
				if (dsts[i].hovaTen[j] >= 'a' && dsts[i].hovaTen[j] <= 'z')
				{
					dsts[i].hovaTen[j] -= 32;
				}
				
			}
		}
	}
}

void doiten2thiSinh(string &ts1, string &ts2)
{
	string temp;
	temp = ts1;
	ts1 = ts2;
	ts2 = temp;
	
	
}
void doitenThiSinh(vector<thiSinh>& dsts)
{	
	doiten2thiSinh(dsts[0].hovaTen, dsts[2].hovaTen);
	doiten2thiSinh(dsts[4].hovaTen, dsts[1].hovaTen);
	
}
void tinhDiem(vector<thiSinh>& dsts)
{	

	for (int i = 0; i < dsts.size(); i++)
	{
		dsts[i].diemtong = dsts[i].toan + dsts[i].van + dsts[i].ngoaiNgu + dsts[i].KHTN + dsts[i].KHXH;
	}
}
void XuatFile(string Filename, vector<thiSinh>dsts)
{
	ofstream out;
	out.open(Filename,ios_base::out);
	for (int i = 0; i < dsts.size(); i++)
	{
		out << dsts[i].id << "," << dsts[i].hovaTen << ",";
		out << dsts[i].KHTN << "," << dsts[i].KHXH << "," << dsts[i].diemtong << endl;
	}
}

int main()
{
	string FileIn = "data.txt";
	string FileOut = "tongketdiemthi.txt";
	vector<thiSinh>dsts = docDanhSachThiSinh(FileIn);
	daoNguocTenThiSinh(dsts);
	vietHoaTenThiSinh(dsts);
	doitenThiSinh(dsts);
	tinhDiem(dsts);
	for (int i = 0; i < dsts.size(); i++)
	{
		cout << dsts[i].id << "," << dsts[i].hovaTen << "," << dsts[i].toan << "," << dsts[i].van << "," << dsts[i].vatLy << ",";
		cout << dsts[i].hoaHoc << "," << dsts[i].sinhHoc << "," << dsts[i].lichSu << "," << dsts[i].diaLy << "," << dsts[i].giaduccongDan << ",";
		cout << dsts[i].KHTN << "," << dsts[i].KHXH << "," << dsts[i].ngoaiNgu << "," << dsts[i].ghichu << "," << dsts[i].tinh << endl;
	}
	XuatFile(FileOut, dsts);
	return 0;
	
}
