#include"Header.h"


int main()
{
	int arr[100], n=0, k=0, i=0, x=0, y=0,m=0;
	int luachon;
	Input(arr, n);
	cout << "Mang da nhap: " << endl;
	Output(arr, n);
	while (true)
	{
		cout << "----------------MENU-----------------" << endl;
		cout << "1:Xoa 1 phan tu bat ky tren mang " << endl;
		cout << "2:Xoa k phan tu tu vi tri i tren mang" << endl;
		cout << "3:Dem so luong va in cac phan tu khac nhau" << endl;
		cout << "4:Dem so luong cac phan tu khac nhau trong doan" << endl;
		cout << "5:So lon thu 2 trong mang" << endl;
		cout << "6:Phan tu xuat hien nhieu nhat" << endl;
		cout << "7:Phan tu nho nhat trong doan" << endl;
		cout << "8:Tong k phan tu lon nhat" << endl;
		cout << "9:Dao nguoc mang" << endl;
		cout << "10:Sap xep phan tu sao cho so chan o dau mang,so le giam dan o cuoi mang" << endl;
		cout << "11:Sap xep so chinh phuong tang dan,cac so khac giu nguyen" << endl;
		cout << "12:Doi cho 2 doan khong dung mang phu" << endl;
		cout << "13:Kiem tra tang dan hay giam dan" << endl;
		cout << "14:In 1 day con tang dan dai nhat" << endl;
		cout << "15:In tat ca cac day con tang(chua hoan thanh)" << endl;
		cout << "16:In ra so nguyen to nho nhat" << endl;
		cout << "0:Ket thuc chuong trinh" << endl;
		cout << "Nhap lua chon: ";cin >> luachon;
		
		switch (luachon)
		{
			case 1:
				
				cout << "Nhap vi tri muon xoa: ";cin >> k;
				XoaViTri(arr, n, k);
				cout << "Mang sau khi xoa phan tu: " << endl;
				Output(arr, n);
				break;
			case 2:
				
				cout << "Nhap so phan tu muon xoa: ";
				cin >> k;
				cout << "Nhap vi tri muon xoa: ";
				cin >> i;
				XoakPhantu(arr, n, k, i);
				cout << "Mang sau khi xoa phan tu: " << endl;
				Output(arr, n);
				break;
			case 3:
				
				Dem_In_phanTuKhacnhau(arr, n);
				break;
			case 4:
				
				cout << "Nhap doan gia tri: " << endl;
				cout << "x= ";
				cin >> x;
				cout << "y= ";
				cin >> y;
				Dem_In_phanTuKhacnhauTrongDoan(arr, n, x, y);
				break;
			case 5:
				
				cout << "Phan tu lon thu 2 la: " << phanTu_Lonthu2(arr, n) << endl;
				break;
			case 6:
				cout << "Phan tu xuat hien nhieu nhat: " << Xuathien_Max(arr, n) << endl;
				break;
			case 7:
				cout << "Nhap doan gia tri: " << endl;
				cout << "x= ";
				cin >> x;
				cout << "y= ";
				cin >> y;
				cout << "Phan tu nho nhat trong doan la: " << timMin_trongDoan(arr, n, x, y) << endl;
				break;
			case 8:
				cout << "Nhap k: ";
				cin >> k;
				cout << "Tong k phan tu lon nhat la: " << kPhantuLientiep_Max(arr, n, k) << endl;
				break;
			case 9:
				daoNguoc_Mang(arr, n);
				cout << "Mang sau khi dao nguoc: " << endl;
				Output(arr, n);
				break;
			case 10:
				sapXep_chanle(arr, n);
				cout << "Mang sau khi sap xep: " << endl;
				Output(arr, n);
				break;
			case 11:
				sapXep_chinhPhuong_Tangdan(arr, n);
				cout << "Mang sau khi sap xep:" << endl;
				Output(arr, n);
			case 12:
				do
				{
					cout << "Nhap vi tri m (m < " << n << "):";
					cin >> m;
					if (m > n)
					{
						cout << "Nhap lai:" << endl;
					}
				} while (m > n);
				doiCho_2doan_mangMoi(arr, n, m);
				cout << "Mang sau khi doi cho:" << endl;
				Output(arr, n);
			case 13:
				if (check_Increasing(arr, n))
				{
					cout << "Mang tang dan" << endl;
				}
				else if (check_Decreasing(arr, n))
				{
					cout << "Mang giam dan" << endl;
				}
				else
				{
					cout << "Mang khong tang cung khong giam" << endl;
				}
				break;
			case 14:
				check_IncreasingLienTuc(arr, n);
				break;
			case 15:
				DayConTangLienTiep(arr, n);
				break;
			case 16:
				cout << "So nguyen to nho nhat" << SoNguyenToNhoNhat(arr, n);
			case 0:
				exit(0);
				break;
		}
	}
	system("pause");
}