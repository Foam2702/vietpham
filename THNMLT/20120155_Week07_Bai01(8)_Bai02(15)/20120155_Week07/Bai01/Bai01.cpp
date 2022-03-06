#include"array.h"

int main()
{
	int n = 0;
	int arr[100];
	int luachon = 0;
	Input(arr, n);
	Output(arr, n);
	while (true)
	{
		cout << "---------------------MENU---------------------" << endl;;
		cout << "1:Tim phan tu lon nhat trong mang 1 chieu" << endl;
		cout << "2:Tinh tong cac so khong am trong mang 1 chieu" << endl;
		cout << "3:Tinh tong cac phan tu tai vi tri chan trong mang 1 chieu" << endl;
		cout << "4:Dem so luong so nguyen to trong mang 1 chieu" << endl;
		cout << "5:Tim phan tu am lon nhat trong mang 1 chieu" << endl;
		cout << "6:Tim phan tu khong am nho nhat trong mang 1 chieu" << endl;
		cout << "7:Kiem tra mang 1 chieu co tang dan khong" << endl;
		cout << "8:Tinh tong cac so chinh phuong trong mang 1 chieu" << endl;
		cout << "0:Thoat" << endl;
		cout << "Nhap lua chon :" ; cin >> luachon;
		
		switch (luachon)
		{
		case 1:

			cout <<"Phan tu lon nhat trong mang :"<< FindMax(arr, n) << endl;
			break;

		case 2:

			cout <<"Tong cac so khong am trong mang :"<< Tong_soKhongam(arr, n) << endl;
			break;


		case 3:

			cout <<"Tong cac so o vi tri chan trong mang :"<< Tong_viTrichan(arr, n) << endl;
			break;

		case 4:

			cout <<"So luong cac so nguyen trong mang :"<< Count_Prime(arr, n) << endl;
			break;

		case 5:
			if (Tim_phantuAmLonNhat(arr, n) == 0)
			{
				cout << "Khong co phan tu am trong mang" << endl;
			}
			else
			{
				cout <<"Phan tu am lon nhat trong mang :"<< Tim_phantuAmLonNhat(arr, n) << endl;
			}
			break;
		case 6:
			if (Tim_phantuKhongAmNhonhat(arr, n) == -1)
			{
				cout << "khong co phan tu khong am trong mang" << endl;
			}
			else
			{
				cout << "Phan tu khong am nho nhat trong mang :"<<Tim_phantuKhongAmNhonhat(arr, n) << endl;
			}
			break;
		case 7:
			if (Check_Increasing(arr, n))
				cout << "Mang tang dan" << endl;
			else
			{
				cout << "Mang khong tang dan" << endl;
			}
			break;
		case 8:
			cout <<"Tong cac so chinh phuong trong mang :"<< Tong_soChinhphuong(arr, n) << endl;
			break;
		case 0:
			exit(0); break;
		}
		cout << endl;
	}
	system("pause");
}