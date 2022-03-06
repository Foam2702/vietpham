#include"Header.h"

void Input_Tinh(Tinh mang_tinh[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ma tinh " << i + 1 << " :";
		cin >> mang_tinh[i].matinh;
		cout << "Nhap ten tinh " << i + 1 << " :";
		cin >> mang_tinh[i].tentinh;
		cout << "Nhap dan so tinh " << i + 1 << " :";
		cin >> mang_tinh[i].danso;
		cout << "Nhap dien tich tinh " << i + 1 << " :";
		cin >> mang_tinh[i].dientich;
	}
}

void Output_Tinh(Tinh tinh)
{
	cout << "Ma Tinh: " << tinh.matinh << endl;
	cout << "Ten Tinh: " << tinh.tentinh << endl;
	cout << "Dan So: " << tinh.danso << endl;
	cout << "Dien tich: " << tinh.dientich << endl << endl;
}

void Output_Tinhdanso(Tinh mang_tinh[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (mang_tinh[i].danso > pow(10, 6))
		{
			Output_Tinh(mang_tinh[i]);
			count++;
		}

	}
	if (count == 0)
	{
		cout << "Khong co tinh nao co dan so lon hon 1.000.000" << endl;
	}
}

void Dientich_Lonnhat(Tinh mang_tinh[], int n)
{
	double max = mang_tinh[0].dientich;
	for (int i = 0; i < n; i++)
	{
		if (max < mang_tinh[i].dientich)
			max = mang_tinh[i].dientich;
	}
	for (int i = 0; i < n; i++)
	{
		if (max = mang_tinh[i].dientich)
		{
			Output_Tinh(mang_tinh[i]);
			break;
		}
	}
}

void Sapxep_Dientich_Giamdan(Tinh mang_tinh[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (mang_tinh[j].dientich > mang_tinh[i].dientich)
				swap(mang_tinh[j], mang_tinh[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		Output_Tinh(mang_tinh[i]);
	}
}