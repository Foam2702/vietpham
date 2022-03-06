#include"Header.h"

int main()
{
	char str[50];
	cout << "Nhap chuoi ky tu:";
	cin.getline(str, 50);
	cout << str<<endl;
	dem_khoangTrang_kySo_laTin_kyTukhac(str);
	cout << "Tu:"<<dem_Tu(str) << endl;
	cout << "Tu dai nhat:"; tu_Dainhat(str); cout << endl;
	cout << "Tu ngan nhat:"; tu_Ngannhat(str); cout << endl;
	cout << "Chuan hoa:"; ChuanHoaChuoi(str);
	system("pause");
}