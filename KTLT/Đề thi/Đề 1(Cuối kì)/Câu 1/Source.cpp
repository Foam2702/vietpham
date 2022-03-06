#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Ngay {
	int ng = 0,th=0,nam=0;
};
struct SINHVIEN {
	int maso=0;
	string hoten;
	bool GioiTinh=true;
	Ngay NgaySinh;
	float Diem=0;
};
struct Node {
	SINHVIEN data;
	Node* next=NULL;
};
struct List {
	Node* Head;
	Node* Tail;
};

Node* CreateNode(SINHVIEN sv) {
	Node* p = new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}
void CreateList(List &l) {
	l.Head = l.Tail = NULL;
}
void AddSVtoList(List& l, SINHVIEN &sv) {
	
	cout << "Nhap ma so:"; cin >> sv.maso; cin.ignore();
	cout << "Nhap ho ten:"; getline(cin, sv.hoten);
	cout << "1:Nam,0:Nu.Nhap:"; cin >> sv.GioiTinh; cin.ignore();
	cout << "Ngay sinh:"; cin >> sv.NgaySinh.ng; cin.ignore(); cout << "Thang sinh:"; cin >> sv.NgaySinh.th; cin.ignore();; cout << "Nam sinh:"; cin >> sv.NgaySinh.nam; cin.ignore();
	cout << "Nhap diem:"; cin >>sv.Diem; cin.ignore();
	Node* p = CreateNode(sv);
	if (l.Head == NULL) {
		l.Head = l.Tail=p;
	}
	else {
		l.Tail->next = p;
		l.Tail = p;
	}
	
}
void FindBirthday(List l) {
	for (Node* g = l.Head; g; g = g->next) {
		for (Node* k = g->next; k; k = k->next) {
			if (g->data.NgaySinh.ng == k->data.NgaySinh.ng) {
				cout << "Ma so:" << g->data.maso << endl;
				cout << "Ho ten:" << g->data.hoten << endl;
				if (g->data.GioiTinh == 1) {
					cout << "Gioi tinh:Nam" << endl;
				}
				else {
					cout << "Gioi tinh:Nu" << endl;
				}
				cout << "Ngay sinh:" << g->data.NgaySinh.ng << "/" << g->data.NgaySinh.th << "/" << g->data.NgaySinh.nam << endl;
				cout << "Diem:" << g->data.Diem << endl;
				cout << endl;
			}
		}
	}
}
void FindBelow_5(List l) {
	for (Node* g = l.Head; g; g = g->next) {
		if (g->data.Diem < 5) {
			cout << "Ma so:" << g->data.maso << endl;
			cout << "Ho ten:" << g->data.hoten << endl;
			if (g->data.GioiTinh == 1) {
				cout << "Gioi tinh:Nam" << endl;
			}
			else {
				cout << "Gioi tinh:Nu" << endl;
			}
			cout << "Ngay sinh:" << g->data.NgaySinh.ng << "/" << g->data.NgaySinh.th << "/" << g->data.NgaySinh.nam << endl;
			cout << "Diem:" << g->data.Diem << endl;
			cout << endl;
		}
	}
}
void ExportSV(List l) {
	for (Node* g = l.Head; g; g = g->next) {
		for (Node* k = g->next; k; k = k->next) {
			if (g->data.maso > k->data.maso) {
				
				swap(g->data, k->data);
			}
		}
	}
	for (Node* g = l.Head; g; g = g->next) {
		cout <<"Ma so:"<< g->data.maso << endl;
		cout <<"Ho ten:"<< g->data.hoten << endl;
		if (g->data.GioiTinh == 1) {
			cout << "Gioi tinh:Nam"<<endl;
		}
		else {
			cout << "Gioi tinh:Nu" << endl;
		}
		cout <<"Ngay sinh:"<< g->data.NgaySinh.ng << "/" << g->data.NgaySinh.th << "/" << g->data.NgaySinh.nam << endl;
		cout <<"Diem:"<< g->data.Diem << endl;
		cout << endl;
	}
	cout << endl;
}
void DestroyList(List& l) {
	Node* p = l.Head;
	while (l.Head) {
		l.Head = l.Head->next;
		delete p;
	}
}
void Write_One_SV(ofstream &FileOut,SINHVIEN sv) {
	FileOut << "MASO:" << sv.maso << endl;
	FileOut << "HO TEN:" << sv.hoten << endl;
	if (sv.GioiTinh == 1) {
		FileOut << "Gioi tinh:Nam" << endl;
	}
	else {
		FileOut << "Gioi tinh:Nu" << endl;
	}
	FileOut <<"NGAY SINH:"<< sv.NgaySinh.ng << "/" << sv.NgaySinh.th << "/" << sv.NgaySinh.nam << endl;
	FileOut << "DIEM:" << sv.Diem <<endl ;
}
void Export_List_to_File(List l) {
	ofstream fileout;
	fileout.open("SINHVIEN.TXT", ios::out);
	for (Node* g = l.Head; g; g = g->next) {
		if (g->data.Diem < 5) {
			Write_One_SV(fileout, g->data);
			fileout << endl;
		}
	}
	fileout.close();
}
void Read_One_SV(string FileName) {
	string line = " ";
	ifstream FileIn;
	FileIn.open(FileName);
	if (FileIn.is_open()) {
		while (getline(FileIn, line)) {
			cout << "\t \t \t   ";
			cout << line << endl;
		}
	}
	else {
		cout << "ERROR";
	}
	
	FileIn.close();
}
void DeleteHead(List& l) {
	if (l.Head == NULL) {
		return;

	}
	else {
		Node* p = l.Head;
		l.Head = l.Head->next;
		delete p;
		return;
	}
}
void DeleteTail(List& l) {
	if (l.Head == NULL) {
		return;
	}
	else {
		for (Node* g = l.Head; g; g = g->next) {
			if (g->next == l.Tail) {
				delete l.Tail;
				g->next = NULL;
				l.Tail = g;
				return;
			}
		}

	}
}


void Delete_sv_below_5(List& l) {

	Node* k = new Node;
	for (Node* g = l.Head; g; g = g->next) {

		if (g->data.Diem < 5) {
			if (l.Head == NULL) {
				return;
			}
			else if (g==l.Head) {
				DeleteHead(l);
				return;
			}
			else if (g==l.Tail) {
				DeleteTail(l);
				return;
			}
			else {
				k->next = g->next;
				delete g;
				return;
			}
		}
		k = g;
	}
}
void Menu(List &l) {
	
	ofstream fileout;
	int choose = 0;
	do {
		system("cls");
		cout << "1:Nhap thong tin sinh vien" << endl;
		cout << "2:Xuat danh sach sinh vien" << endl;
		cout << "3:Tim sinh vien co trung ngay sinh nhat" << endl;
		cout << "4:Ghi vao file" << endl;
		cout << "5:Doc tu file in ra man hinh" << endl;
		cout << "6:Xoa sinh vien co diem duoi 5" << endl;
		cout << "0:Thoat"<<endl;
		cout << "Nhap lua chon:"; cin >> choose; cin.ignore();

		switch (choose)
		{
			case 1: {
				SINHVIEN sv;
				AddSVtoList(l, sv);
				
				break;
			}
			case 2: {
				ExportSV(l);
				system("pause");
				break;
			}
			case 3: {
				FindBirthday(l);
				system("pause");
				break;
			}
			case 4: {
				Export_List_to_File(l);
				break;
			}
			case 5: {
				Read_One_SV("SINHVIEN.TXT");
				system("pause");
				break;
			}
			case 6: {
				Delete_sv_below_5(l);
				break;
			}
		}
		
	} while (choose != 0);
}

int main() {
	
	List l;
	CreateList(l);
	Menu(l);
	DestroyList(l);
	return 0;
}
