#include <iostream>
#include <string>
#include <list>
using namespace std;
#define MAX 30

void NhapDuLieu(string &str, list<char> &l)
{
	bool KiemTraVietThuong;
	int length;
	do{
		KiemTraVietThuong = true;

		cout << "\nNhap vao chuoi: ";
		//cin >> str; // char str[100]; scanf("%s", str);
		getline(cin, str); // gets(str);

		length = str.length();
		for(int i = 0; i < length; ++i)
		{
			l.push_back(str[i]);
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				KiemTraVietThuong = false;
				l.clear();
				break;
			}
		}

		if(length > MAX)
			cout << "\nChuoi ky tu chi duoc phep toi da " << MAX << " ky tu. Xin kiem tra lai!";
		
		if(KiemTraVietThuong == false)
			cout << "\nTat ca cac ky tu trong chuoi phai viet thuong. Xin kiem tra lai!";

	}while(length > MAX || KiemTraVietThuong == false);

	// Khi chuỗi đã hợp lệ thì sẽ tiến hành bóc tách từng ký tự trong chuỗi lưu vào danh sách liên kết
	/*for(int i = 0; i < length; ++i)
	{
		l.push_back(str[i]);
		//l.push_front(str[i]);
	}*/
}

void XuatDuLieu(list<char> l)
{
	// for(int i = 0; i < n; i++)
	cout << "\nXuat theo chieu xuoi: ";
	for(list<char>::iterator it = l.begin(); it != l.end(); ++it) //for(auto it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";

	/*
	cout << "\nXuat theo chieu nguoc: ";
	for(list<char>::reverse_iterator rit = l.rbegin(); rit != l.rend(); ++rit) //for(auto rit = l.rbegin(); rit != l.rend(); ++rit)
		cout << *rit << " ";
		*/
}

// true: nếu giống nhau; false: nếu không giống nhau
// Cách làm: Chỉ cần kiểm tra tại vị trí bất kỳ có sự khác nhau => lập tức kết luận không giống nhau. Còn nếu đi đến cuối cùng danh sách mà tất cả đều giống nhau => giống nhau
bool KiemTraDanhSachDaoNguocGiongBanDau(list<char> l)
{
	list<char>::iterator it = l.begin();
	list<char>::reverse_iterator rit = l.rbegin();
	int size = l.size();

	for(int i = 0; i < size / 2; ++i, ++it, ++rit)
	{
		if(*it != *rit)
			return false;
	}
	return true;
}

int main()
{
	string str;
	list<char> l;

	NhapDuLieu(str, l);
	XuatDuLieu(l);

	bool KiemTra = KiemTraDanhSachDaoNguocGiongBanDau(l);
	if(KiemTra == true)
		cout << "\nDanh sach sau khi dao lai giong ban dau";
	else
		cout << "\nDanh sach sau khi dao lai khac ban dau";

	system("pause"); // <=> getch();
	return 0;
}