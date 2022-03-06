#include"Header.h"

int main()
{
	double n;
	do
	{
		cout << "Nhap so tien :";
		cin >> n;
		if (n <1.000)
		{
			cout << "So tien phai lon hon 1.000" << endl;
		}
	} while (n < 1.000);
	soTo_cua_tungLoaiTien(n);
	system("pause");
}