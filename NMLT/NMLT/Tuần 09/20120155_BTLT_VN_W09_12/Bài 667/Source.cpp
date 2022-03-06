#include"Header.h"


void ReadFile(ifstream& in, Tinh mang_tinh[], int& n)
{	
	
	for (int i = 0; i < n; i++)
	{
		in >> mang_tinh[i].matinh;
		
		in.getline(mang_tinh[i].tentinh,30);
		in.ignore();
		in >> mang_tinh[i].danso ;
		in >> mang_tinh[i].dientich;
		
	}
}
void Output(ofstream& out, Tinh tinh)
{
	out <<  tinh.matinh<<";";
	out <<  tinh.tentinh <<";";
	out <<  tinh.danso<<";";
	out <<  tinh.dientich << endl;
}

Tinh Dientich_Lonnhat( Tinh mang_tinh[], int n)
{	
	Tinh tinh_max_dt;
	double max = mang_tinh[0].dientich;
	for (int i = 1; i < n; i++)
	{
		if (max < mang_tinh[i].dientich)
			max = mang_tinh[i].dientich;
	}
	for (int i = 0; i < n; i++)
	{
		if (max == mang_tinh[i].dientich)
		{
			tinh_max_dt = mang_tinh[i];
			break;
		}
	}
	return tinh_max_dt;
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
	
	
}
void WriteFile(ofstream &out, Tinh mang_tinh[], int n)
{	
	int count = 0;
	out << "Cac tinh co dan so lon hon 1.000.000" << endl;
	for (int i = 0; i < n; i++)
	{
		if (mang_tinh[i].danso > pow(10, 6))
		{
			Output(out, mang_tinh[i]);
			count++;
		}

	}
	if (count == 0)
	{
		out << "Khong co tinh nao co dan so lon hon 1.000.000" << endl;
	}
	
	
	out << "Tinh co dien tich lon nhat :"<<endl;
	Output(out, Dientich_Lonnhat(mang_tinh, n));

	out << "Cac tinh sau khi sap xep theo thu tu giam dan dien tich:" << endl;
	Sapxep_Dientich_Giamdan(mang_tinh, n);
	for (int i = 0; i < n; i++)
	{
		Output(out, mang_tinh[i]);
	}
}

