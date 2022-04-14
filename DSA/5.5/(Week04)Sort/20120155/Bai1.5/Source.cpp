#include<iostream>
#include<vector>
#include<string>
using namespace std;


struct SinhVien
{
	string MSSV = "";
	double diem = 0;
};

vector<SinhVien> SortScore(vector<SinhVien> arr)
{
	
	size_t size = arr.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (size_t j = size - 1; j > i; j--)
		{
			if (arr[j].diem < arr[static_cast<__int64>(j) - 1].diem)
				swap(arr[j], arr[static_cast<__int64>(j) - 1]);
		}
	}
	return arr;

}
void ExportDSSV(vector<SinhVien> arr)
{
	size_t size = arr.size();
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].MSSV << " ";
	}
}
int main()
{
	vector<SinhVien> dssv,newdssv;
	SinhVien sv;
	int n;
	cout << "So luong sinh vien:"; cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "MSSV:"; getline(cin, sv.MSSV);
		cout << "Diem:"; cin >> sv.diem;
		dssv.push_back(sv);
		
	}
	newdssv = SortScore(dssv);
	ExportDSSV(newdssv);
	

}