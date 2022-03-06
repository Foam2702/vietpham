#include<iostream>
#include<vector>
using namespace std;

struct NgaySinh {
	int ngay, thang, nam;
};
struct Student {
	char hoten[30];
	char maso[10];
	NgaySinh day;
	double Marks[3];
	double DTB;
};

void Ranked(Student student)
{
	
	if (student.DTB < 5)
	{
		cout << "Xep loai:Yeu";
	}
	else if (student.DTB >= 5 && student.DTB < 7)
	{
		cout << "Xep loai:Trung binh";
	}
	else if (student.DTB >= 7 && student.DTB < 8)
	{
		cout << "Xep loai:Kha";
	}
	else
	{
		cout << "Xep loai:Gioi";
	}
	
}



void Input(vector<Student>&arr)
{
	Student student;
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{	
		cin.ignore();
		cout << "STUDENT " << i + 1<<":"<<endl;
		cout << "Nhap ho ten: ";
		cin.getline(student.hoten, 30);

		cout << "Nhap ma so: ";
		cin.getline(student.maso, 10);

		cout << "Ngay/Thang/Nam: ";
		cin >> student.day.ngay >> student.day.thang >> student.day.nam;
		cout << "BT/GK/CK: ";

		for (int j = 0; j < 3; j++)
		{
			cin >> student.Marks[j];
		}

		student.DTB = student.Marks[0] * 0.25 + student.Marks[1] * 0.25 + student.Marks[2] * 0.5;
		arr.push_back(student);
		cout << endl << endl;
	}
}
void Export(vector<Student>&arr)
{	
	for (int i = 0; i < arr.size()-1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (strlen(arr[i].maso) > strlen(arr[j].maso))
			{
			
				swap(arr[i], arr[j]);
				
			}
		}
	}
	
	for (int i = 0; i < arr.size(); i++)
	{	
		cout << "--STUDENT" << i + 1 << "--"<<endl;
		cout << "Ho ten:"<<arr[i].hoten<<endl;
		cout << "Ma so:" << arr[i].maso << endl;
		cout << "Ngay/thang/nam:" << arr[i].day.ngay << "/" << arr[i].day.thang << "/" << arr[i].day.nam<< endl;
		cout << "BT/GK/CK:" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i].Marks[j]<<" ";
		}
		cout << endl<<arr[i].DTB<<endl;
		Ranked(arr[i]);
		cout << endl<<endl;
	}
}
void AddtoList(vector<Student>& arr)
{	
	Student student;
	cin.ignore();
	cout << "STUDENT " << arr.size() + 1 << ":" << endl;
	cout << "Nhap ho ten: ";
	cin.getline(student.hoten, 30);

	cout << "Nhap ma so: ";
	cin.getline(student.maso, 10);

	cout << "Ngay/Thang/Nam: ";
	cin >> student.day.ngay >> student.day.thang >> student.day.nam;
	cout << "BT/GK/CK: ";

	for (int j = 0; j < 3; j++)
	{
		cin >> student.Marks[j];
	}
	student.DTB = student.Marks[0] * 0.25 + student.Marks[1] * 0.25 + student.Marks[2] * 0.5;
	arr.push_back(student);
	
}
void Xoa_Xeploai_Yeu(vector<Student>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].DTB < 5)
		{
			arr.erase(arr.begin()+i);
		}
	}
	cout << "Da xoa thanh cong";
}
void Find_Birthday(vector<Student>arr)
{
	
	for (int i = 0; i < arr.size()-1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i].day.ngay == arr[j].day.ngay && arr[i].day.thang == arr[i].day.thang)
			{
				cout << "--STUDENT" << i + 1 << "--" << endl;
				cout << "Ho ten:" << arr[i].hoten << endl;
				cout << "Ma so:" << arr[i].maso << endl;
				cout << "Ngay/thang/nam:" << arr[i].day.ngay << "/" << arr[i].day.thang << "/" << arr[i].day.nam << endl;
				cout << "BT/GK/CK:" << endl;
				for (int k = 0; k < 3; k++)
				{
					cout << arr[i].Marks[k] << " ";
				}
				cout << endl << arr[i].DTB << endl;
				Ranked(arr[i]);
				cout << endl << endl;

				cout << "--STUDENT" << j + 1 << "--" << endl;
				cout << "Ho ten:" << arr[j].hoten << endl;
				cout << "Ma so:" << arr[j].maso << endl;
				cout << "Ngay/thang/nam:" << arr[j].day.ngay << "/" << arr[j].day.thang << "/" << arr[j].day.nam << endl;
				cout << "BT/GK/CK:" << endl;
				for (int k = 0; k < 3; k++)
				{
					cout << arr[j].Marks[k] << " ";
				}
				cout << endl << arr[j].DTB << endl;
				Ranked(arr[j]);
				cout << endl << endl;
			}
		}
	}
	
}
void Menu()
{
	vector<Student>arr;
	int choose;
	while (true)
	{
		system("cls");
		cout << "1:Nhap danh sach sien vien" << endl;
		cout << "2:Xuat danh sach sinh vien theo xep loai" << endl;
		cout << "3:Them sinh vien vao danh sach"<<endl;
		cout << "4:Xoa tat ca sinh vien xep loai yeu" << endl;
		cout << "5:Tim tat ca sinh vien cung ngay sinh nhat" << endl;
		cout << "0:Thoat"<<endl;
		cout << "Nhap lua chon:"<<endl;
		cin >> choose;
		switch(choose)
		{
		case 1:
			Input(arr);
			break;
		case 2:
			Export(arr);
			system("pause");
			break;
		case 3:
			AddtoList(arr);
			break;
		case 4:	
			Xoa_Xeploai_Yeu(arr);
			system("pause");
			break;
		case 5:
			Find_Birthday(arr);
			system("pause");
			break;

		case 0:
			exit(0);
			break;
		}
	}
}

int main()
{
	Menu();
	return 0;
}