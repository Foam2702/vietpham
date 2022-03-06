#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

struct HocSinh
{
	string Ma, Ten, DiaChi;
	float DiemTrungBinh;
};
typedef struct HocSinh HOCSINH;

void NhapHocSinh(HOCSINH &x)
{
	fflush(stdin);
	cout << "\nNhap vao ten: ";
	getline(cin, x.Ten);

	fflush(stdin);
	cout << "\nNhap vao dia chi: ";
	getline(cin, x.DiaChi);

	do{
		cout << "\nNhap vao diem trung binh: ";
		cin >> x.DiemTrungBinh;

		if(x.DiemTrungBinh < 0 || x.DiemTrungBinh > 10)
			cout << "\nDiem trung binh chi duoc phep nam trong doan tu 0 den 10. Xin kiem tra lai!";

	}while(x.DiemTrungBinh < 0 || x.DiemTrungBinh > 10);
}

void XuatHocSinh(HOCSINH x)
{
	cout << "\nMa so: " << x.Ma;
	cout << "\nTen: " << x.Ten;
	cout << "\nDia chi: " << x.DiaChi;
	cout << "\nDiem trung binh: " << x.DiemTrungBinh; 
}

void NhapDuLieu(forward_list<HOCSINH> &l)
{
	int n;

	do{
		cout << "\nNhap vao so luong hoc sinh co trong danh sach: ";
		cin >> n;

		if(n < 0)
			cout << "\nSo luong hoc sinh khong duoc la so am. Xin kiem tra lai!";
	}while(n < 0);

	for(int i = 1; i <= n; ++i)
	{
		HOCSINH x;
		cout << "\nNhap vao hoc sinh thu " << i << ": ";
		
		bool Check;
		do{
			fflush(stdin);
			cout << "\nNhap vao ma so: ";
			getline(cin, x.Ma);

			Check = false; // mặc định là false tức là không bị trùng
			for(auto it = l.begin(); it != l.end(); ++it) // vòng lặp duyệt qua danh sách các học sinh đang có hiện tại kiểm tra xem mã số vừa nhập cho học sinh mới có bị trùng với các mã số đã có của các học sinh trước đó hay không?
			{
				if(it->Ma == x.Ma) // Nếu bị trùng => cập nhật Check = true - dừng vòng lặp lại và bắt nhập lại
				{
					cout << "\nMa so nay da bi trung voi cac hoc sinh truoc do. Xin vui long nhap lai!";
					Check = true;
					break; // đã phát hiện bị trùng thì không cần duyệt tiếp nữa
				}
			}
		}while(Check == true);

		NhapHocSinh(x);
		l.push_front(x);
	}
}

void XuatDuLieu(forward_list<HOCSINH> l)
{
	//for(int i = 0; i < n; ++i)
	//for(auto it = l.begin(); it != l.end(); it++)
	int dem = 1;
	for(forward_list<HOCSINH>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "\n\nThong tin hoc sinh thu " << dem++ << " la";
		XuatHocSinh(*it);
	}
}

//bool KiemTraSoChan(int value)
//{
//	/*if(value % 2 == 0)
//		return true;
//
//	return false;*/
//
//	return value % 2 == 0;
//}

bool KiemTraDiemTrungBinhDuoi5(HOCSINH x)
{
	/*if(x.DiemTrungBinh < 5)
		return true;

	return false;*/

	return x.DiemTrungBinh < 5;
}

int main()
{
	forward_list<HOCSINH> l;
	NhapDuLieu(l);
	XuatDuLieu(l);

	cout << "\nXoa tat ca hoc sinh co diem trung binh < 5 trong danh sach\n";
	l.remove_if(KiemTraDiemTrungBinhDuoi5);
	XuatDuLieu(l);

	system("pause");
	return 0;
}