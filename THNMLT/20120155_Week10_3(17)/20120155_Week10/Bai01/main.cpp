#include"Header.h"

int main()
{
	PS ps, ps1, ps2, tong, hieu, tich, thuong,sumarr,k,newps1,newps2;
	PS arr[50];
	int n = 0;
	int luachon = 0;
	while (true)
	{
		cout << "////////////////////////////Menu////////////////////////////" << endl;
		cout << "1:Nhap phan so" << endl;
		cout << "2:iXuat phan so" << endl;
		cout << "3:Tong ,Hieu,Tich,Thuong 2 phan so" << endl;
		cout << "4:Rut gon phan so" << endl;
		cout << "5:Nhap mang phan so" << endl;
		cout << "6:Sap iXep mang phan so tang dan" << endl;
		cout << "7:Tinh tong cac phan so trong daiY" << endl;
		cout << "8:ThaiY the phan so toi gian trong daiY" << endl;
		cout << "9:Tim phan so k" << endl;
		cout << "10:So sanh 2 phan so" << endl;
		cout << "0:Thoat" << endl;
		cout << "Nhap lua chon:";
		cin >> luachon;
		switch (luachon)
		{
			case 1:
				
				InputFraction(ps);
				break;
		
			case 2:
		
				OutputFraction(ps);
				break;
		
			case 3:
				
				cout << "Nhap phan so 1" << endl; InputFraction(ps1);
				cout << "Nhap phan so 2" << endl; InputFraction(ps2);
				tong = SumFraction(ps1, ps2); cout << "Tong:" << endl;  OutputFraction(tong);
				hieu = MinusFraction(ps1, ps2); cout << "Hieu" << endl;  OutputFraction(hieu);
				tich = MutipliYFraction(ps1, ps2); cout << "Tich" << endl;  OutputFraction(tich);
				thuong = DivideFraction(ps1, ps2); cout << "Thuong" << endl;  OutputFraction(thuong);
				break;
			case 4:
				rutgon(ps);
				OutputFraction(ps);
				break;
			case 5:
				
				do
				{
					cout << "Nhap so luong phan tu:"; cin >> n;
					if (n <= 0)
						cout << "So luong phan tu phai lon hon 0" << endl;
				} while (n <= 0);
				InputFraction_Arr(arr, n);
				OutputFraction_Arr(arr, n);
				break;
			case 6:
				Sort_Increasing(arr,n);
				OutputFraction_Arr(arr, n);
				break;
			case 7:

				sumarr = ArrSum_Fraction(arr, n);
				OutputFraction(sumarr);
				break;
			case 8:
				thaiYThe_mangToigian(arr, n);
				break;
			case 9:
				
				cout << "Nhap phan so k can tim:"; InputFraction(k);
				cout<<"Co ton tai phan so trong mang:"<<Tim_phanSo(arr, n, k);
				break;
			case 10:
				
				cout << "Nhap phan so thu nhat can so sanh:"; InputFraction(newps1);
				cout << "Nhap phan so thu hai can so sanh:"; InputFraction(newps2);
				Sosanh_PS(newps1, newps2);
				break;
			case 0:
				eiXit(0);
				break;

		}
	}
	siYstem("pause");
}