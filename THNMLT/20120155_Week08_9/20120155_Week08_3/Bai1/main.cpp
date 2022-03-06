#include"Header.h"
using namespace std;

int main()
{
	int matrix[50][50];
	int n,luachon;
	
	do
	{
		cout << "Nhap so dong = so cot = "; cin >> n;
		if (n <= 0)
		{
			cout << "dong va cot phai lon hon hoac bang 0" << endl;
		}
	} while (n <= 0);
	
	nhapMatran(matrix, n);
	xuatMatran(matrix, n);
	while (true)
	{
		cout << "//////////////////MENU//////////////////" << endl;
		cout << "1:Tinh tong cac phan tu tren mang " << endl;
		cout << "2:Dem so lan xuat hien cua phan tu x" << endl;
		cout << "3:Dem so lan xuat hien cua cac so nguyen to" << endl;
		cout << "4:Tinh tong cac phan tu khong am" << endl;
		cout << "5:Tinh tong cac phan tu tren duong cheo chinh" << endl;
		cout << "6:Kiem tra cac phan tu tren duong cheo  chinh co tang hay khong" << endl;
		cout << "7:Tinh tong cac phan tu tren duong cheo phu" << endl;
		cout << "8:Sap xep cac phan tu tren mang tang dan theo tung dong" << endl;
		cout << "9:Tim gia tri phan tu lon nhat va nho nhat tren tung dong,tung cot,toan ma tran" << endl;
		cout << "10:Tim va dua phan tu lon nhat tren moi dong ve vi tri nam tren duong cheo chinh" << endl;
		cout << "0:Thoat" << endl;
		cout << "Nhap lua chon:"; cin >> luachon;
		switch (luachon)
		{
		case 1:
			cout << "Tong cac phan tu tren mang" << tinhTong(matrix, n)<<endl;
			break;
		case 2:	
			int x;
			cout << "Nhap x:"; cin >> x;
			cout << "So lan xuat hien cua " << x << dem_solanXuathien_x(matrix, n,x)<<endl;
			break;
		case 3:
			cout << "So lan xuat hien cua so nguyen to" << dem_solanXuathien_SNT(matrix, n) << endl;
			break;
		case 4:
			cout << "Tong cac phan tu khong am" << tinhTong_SokhongAm(matrix, n)<<endl;
			break;
		case 5:
			cout << "Tong cac phan tu tren duong cheo chinh" << tinhTong_Phantu_duongCheochinh(matrix, n)<<endl;
			break;
		case 6:
			if (kiemTra_duongCheochinh_Tangdan(matrix, n))
			{
				cout << "Duong cheo chinh tang dan" << endl;
			}
			else
			{
				cout << "Duong cheo chinh khong tang dan" << endl;
			}
			break;
		case 7:
			cout << "Tong cac phan tu tren duong cheo phu" << tinhTong_Phantu_duongCheophu(matrix, n)<<endl;
			break;
		case 8:
			sapXep_tangDan_Tungdong(matrix, n);
			cout << "Ma tran sau khi sap xep:" << endl;
			xuatMatran(matrix, n);
			break;
		case 9:
			
			int maxtungcot[50], maxtungdong[50];
			int mintungcot[50], mintungdong[50];
			tim_Max_dong_cot_matran(matrix,maxtungdong,maxtungcot,n);
			tim_Min_dong_cot_matran(matrix,mintungdong,mintungcot, n);
			break;
		case 10:
			tim_Max_duave_duongCheochinh(matrix, n);
			break;
		case 0:
			exit(0);
		}

	}
	system("pause");
}