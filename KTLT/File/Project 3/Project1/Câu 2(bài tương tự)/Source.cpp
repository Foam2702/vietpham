#include<iostream>
using namespace std;
#include<fstream>

// khai báo cấu trúc phân số
struct PHANSO
{
	int tuso;
	int mauso;
};

// khai báo cấu trúc danh sách phân số
struct DANHSACH
{
	PHANSO ds_ps[100];
	int n;
};


// hàm đọc 1 phân số
void Doc_1_Phan_So(PHANSO& ps, ifstream& filein)
{
	filein >> ps.tuso;
	/*char x;
	filein >> x;*/
	filein >> ps.mauso;
}

// hàm đọc file
void Doc_File(DANHSACH& ds, ifstream& filein)
{
	filein >> ds.n;
	for (int i = 0; i < ds.n; i++)
	{
		Doc_1_Phan_So(ds.ds_ps[i], filein);
	}
}

// hàm xuất danh sách phân số
void Xuat_Danh_Sach_Phan_So(DANHSACH ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		cout << ds.ds_ps[i].tuso << "/" << ds.ds_ps[i].mauso << endl;
	}
}

int main()
{
	ifstream filein;
	filein.open("phanso.txt", ios_base::in);
	DANHSACH ds;
	Doc_File(ds, filein);
	Xuat_Danh_Sach_Phan_So(ds);
	filein.close();
	system("pause");
	return 0;
}