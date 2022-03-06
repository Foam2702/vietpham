#include<iostream>
#include<string>
using namespace std;
struct Marks {
	float baitap=0;
	float giuaky=0;
	float cuoiky=0;
};
struct Student{
	string id;
	string name;
	Marks diem;
	double dtb=0;
};
void InputStudent(Student &sv) {
	cout << "ID :";
	getline(cin, sv.id);
	cout << "NAME:";
	getline(cin, sv.name);
	do {
		cout << "MARKS: baitap,giuaky,cuoiky:";
		cin >> sv.diem.baitap >> sv.diem.giuaky >> sv.diem.cuoiky;
		if (sv.diem.baitap < 0 || sv.diem.giuaky < 0 || sv.diem.cuoiky < 0) {
			cout << "Diem phai lon hon 0"<<"\n";
		}
	} while(sv.diem.baitap <0|| sv.diem.giuaky<0 || sv.diem.cuoiky<0);
	sv.dtb = sv.diem.baitap * 0.25 + sv.diem.giuaky * 0.25 + sv.diem.cuoiky * 0.5;
	cout << "DTB:" << sv.dtb<<endl;
}
void OutputStudent(Student sv) {
	cout << "ID:" << sv.id << "\n";
	cout << "Name:" << sv.name << "\n";
	cout << "Bai tap:" << sv.diem.baitap << "\n" << "Giua ky:" << sv.diem.giuaky << "\n" << "Cuoi ky:" << sv.diem.cuoiky << "\n";
	cout << "DTB:" << sv.dtb << "\n";
}
void OutputListStudent(Student*list,int &n) {
	for (int i = 0; i <n ; i++) {
		cout << "Sinh vien thu " << i + 1 << endl;
		OutputStudent(list[i]);
	}
}
void Ranked(Student* &list, int& n) {
	for (int i = 0; i < n ; i++) {
		cout << "\n";
		cout << "Thong tin SV thu " << i + 1 << "\n";
		if (list[i].dtb < 5) {
			OutputStudent(list[i]);
			cout << "Loai:Yeu" << "\n";;
		}
		else if (list[i].dtb >= 5 && list[i].dtb <= 7) {
			OutputStudent(list[i]);
			cout << "Loai:Trung Binh"<< "\n";
		}
		else if (list[i].dtb >= 7 && list[i].dtb <= 8) {
			OutputStudent(list[i]);
			cout << "Loai:Kha"<< "\n";
		}
		else {
			OutputStudent(list[i]);
			cout << "Loai:Gioi"<< "\n";
		}
	}
}
void AddtoList(Student* &list, Student* sv,int &n) {
	for(int i = 0; i < n; i++) {
		list[i] = *sv;
	}
}
void addNewStudenttoList(Student* &list, int& n) {
	Student* sv = new Student;
	InputStudent(*sv);
	n++;
	Student* seclist = new Student[n];
	for (int i = 0; i < n-1; i++) {
		seclist[i] = list[i];
	}
	n--;
	seclist[n] = *sv;
	delete[] list;
	n++;
	list = new Student[n];
	for (int i = 0; i < n; i++) {
		list[i] = seclist[i];
	}
	delete[]seclist;
}
void DeleteStudent_Under5(Student* &list, int& n) {
	Student* seclist = new Student[n];
	int count = n;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (list[i].dtb > 5) {
			seclist[j] = list[i];
			count--;
			j++;
		}
	}
	delete[]list;
	n = count;
	list = new Student[n];
	for (int i = 0; i < n; i++) {
		list[i] = seclist[i];
	}
	delete[]seclist;
}

void Menu() {
	int choose=0;
	int n = 0;
	cout << "Nhap so luong sinh vien :"; cin >> n;
	Student* list = new Student[n];
	while (true) {
		system("cls");
		cout << "1:Nhap thong tin sinh vien"<<endl;
		cout << "2:Xuat thong tin sinh vien co xep loai" << endl;
		cout << "3:Them sinh vien vao danh sach" << endl;
		cout << "4:Xoa sinh vien co dtb <5 va xuat lai danh sach" << endl;
		cout << "0:Thoat"<<endl;
		cout << "Nhap lua chon :"; cin >> choose;
		cin.ignore();
		if (choose == 1) {
			Student* sv = new Student;
			InputStudent(*sv);
			AddtoList(list,sv,n);
		}
		else if (choose == 2) {
			Ranked(list,n);
			system("pause");
		}
		else if (choose == 3) {
			addNewStudenttoList(list, n);


			system("pause");

		}
		else if (choose == 4) {
			DeleteStudent_Under5(list, n);
			Ranked(list, n);
			system("pause");
		}
		else if (choose == 0) {
			delete[]list;
			break;
		}
	}
}

int main()
{	
	Menu();
	system("pause");
	return 0;
	
}