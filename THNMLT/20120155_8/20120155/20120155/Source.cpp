#include"Header.h"



void Input_1Xe(Xe &xe)
{	
	
	do {
		cin.ignore();
		cin.clear();
		cout << "Nhap nhan hieu:";
		cin.getline(xe.nhanhieu, 30);
		cout << "Nhap mau sac:";
		cin >> xe.mausac;
		cout << "Nhap diem danh gia:";
		cin >> xe.diem;
		if (strlen(xe.nhanhieu) > 30)
		{
			cout << "Chieu dai nhan hieu phai <=30" << endl;
		}
		if (xe.mausac != 'w' && xe.mausac != 'b' && xe.mausac != 'r' && xe.mausac != 'g')
		{
			cout << "Mau sac chi nhan 4 gia tri 'w','b','r','g'" << endl;

		}
		if (xe.diem < 1 || xe.diem>10)
		{
			cout << "Diem phai thuoc doan [1;10]" << endl;
		}

	} while (strlen(xe.nhanhieu) > 30 || xe.mausac != 'w' && xe.mausac != 'b' && xe.mausac != 'r' && xe.mausac != 'g' || xe.diem < 1 || xe.diem>10);
	
}
void Input_DsXe(Xe list[], int n)
{	
	cout << "NHAP:" << endl<<endl;
	for (int i = 0; i < n; i++)
	{	
		Input_1Xe(list[i]);
		cout << endl;
		
	}
}
void Output_1Xe(Xe xe)
{	
	cout << "XUAT:"<<endl<<endl;
	cout << "Nhan hieu:" << xe.nhanhieu << endl;
	cout << "Mau sac:" << xe.mausac << endl;
	cout << "Diem danh gia:" << xe.diem << endl;
}
void Output_DsXe(Xe list[], int n)
{	
	cout << "XUAT:" << endl<<endl;
	for (int i = 0; i < n; i++)
	{
		Output_1Xe(list[i]);
		cout << endl;
	}
}
bool check(Xe xe)//hàm kiểm tra nếu từ ký tự 2 có 3 chữ cái là "oyo"
{
	
	if (xe.nhanhieu[1] == 'o' && xe.nhanhieu[2] == 'y' && xe.nhanhieu[3] == 'o')
		return true;
	return false;
	
}
void Dem_Xuat_Toyota_8(Xe list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (check(list[i]) == true && list[i].diem >= 8)//nếu từ ký tự 2 có 3 chữ cái là "oyo" và có điểm lớn hơn hoặc bằng 8
		{
			Output_1Xe(list[i]);
		}
	}
}
void Sapxep_Mausac(Xe xe1,Xe xe2)
{
	
	
	if (xe1.mausac == 'b' && xe2.mausac == 'w')
		swap(xe1, xe2);
	if (xe1.mausac == 'r' && (xe2.mausac == 'w' || xe2.mausac == 'b'))
		swap(xe1, xe2);
	if(xe1.mausac=='g'&&(xe2.mausac == 'w' || xe2.mausac == 'b'||xe2.mausac=='r'))
		swap(xe1, xe2);
		
	
	
}
void Sapxep_Alphabet(Xe list[], int n)
{	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (strcmp(list[i].nhanhieu, list[j].nhanhieu) > 0) //so sánh alphabet
			{
				swap(list[i], list[j]);//đổi chổ 2 xe
			}
			if (strcmp(list[i].nhanhieu, list[j].nhanhieu) == 0)
			{
				Sapxep_Mausac(list[i], list[j]);
			}
		}
	}
	Output_DsXe(list, n);
}