//Biện Viết Phẩm-20120155
#include"Header.h"

int main()
{	
	
	while (true)
	{
		int luachon;
		
		cout << "MENU"<<endl;
		cout << "1:Bai 1" << endl;
		cout << "2:Bai 2" << endl;
		cout << "3:Bai 3" << endl;
		cout << "0:Thoat" << endl;
		cout << "Nhap lua chon:"; cin >> luachon;
		if (luachon == 1)
		{
			int n = 0;
			Input1(n);
			In_SochinhPhuong_nhoHon_n_Chiahetcho3(n);

		}
		else if (luachon == 2)
		{
			int n = 0;
			Input2(n);
			cout << TinhTong_cacvitriLe(n);
		}
		else if (luachon == 3)
		{
			int n = 0;
			Input3(n);
			Kiemtra_DangSong( n);
		}
		else {
			exit(0);
		}
		cout << endl;
	}
	system("pause");
	
}