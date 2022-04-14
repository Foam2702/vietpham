#include<iostream>
#include<string>
using namespace std;

struct Phim {
	string maso="";
	string tenPhim="";
	string nhaSX="";
	int namSX=0;
	float XepHang=0;
};

struct Node {
	Phim data;
	Node* Next = NULL;
};
struct List {
	Node* Head = NULL;
	Node* Tail = NULL;
};

Node* createNode(Phim value) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "NOT ENOUGH MEMORY" << endl;
	}
	else {
		p->data = value;
		p->Next = NULL;
		
	}
	return p;
}
/*Them 1 node vao dau LList*/
void addFirst(List& l, Node* p) {

	if (l.Head == NULL) {
		l.Head = p;
	}
	else {
		p->Next = l.Head;
		l.Head = p;
	}
}
/*Them 1 node vao cuoi LList*/
void addLast(List& l, Node* p) {

	if (l.Head == NULL) {
		l.Head = p;
	}
	else {
		Node* g = l.Head;
		while (g->Next) {
			g = g->Next;
		}
		g->Next = p;
	}
}
void sapxep_Namsanxuat(List& l) {
	for (Node* g = l.Head; g; g = g->Next) {
		for (Node* h = g->Next; h; h = h->Next) {
			if (g->data.namSX > h->data.namSX) {
				swap(g->data, h->data);
			}
		}
	}
}
void xoa_nsxHBO(List& l) {
	Phim phim;
	Node* temp = l.Head;
	Node* prev = NULL;
	string key = "HBO";
	if (temp != NULL && temp->data.nhaSX == key) {
		l.Head = temp->Next;
		delete temp;
		return;
	}

	while (temp != NULL && temp->data.nhaSX != key) {
		prev = temp;
		temp = temp->Next;
	}


	if (temp == NULL) return;


	prev->Next = temp->Next;

	delete temp;
}
void dsNhap(List& l) {
	int n = 0;
	Phim phim;
	Node* p;
	cout << "NHAP DANH SACH" << endl;
	cout << "Nhap so luong phim can nhap:"; cin >> n;
	for (int i = 0; i < n; i++) {
		cin.clear();
		cin.ignore();
		cout << "Ma so:"; getline(cin,phim.maso);
		cout << "Ten phim:"; getline(cin, phim.tenPhim);
		cout << "Nha san xuat:"; getline(cin, phim.nhaSX);
		cout << "Nam san xuat:"; cin >> phim.namSX;
		cout << "Xep hang:"; cin >> phim.XepHang; 
		p = createNode(phim);
		addLast(l, p);
		cout << endl;
	}
	
	cout << endl;
}

void dsXuat(List l) {

	cout << "XUAT DANH SACH"<<endl;
	for (Node* g = l.Head; g; g = g->Next) {
		cout << "Ma so:" << g->data.maso << endl;
		cout << "Ten phim:" << g->data.tenPhim<<endl;
		cout << "Nha san xuat:" << g->data.nhaSX<<endl;
		cout << "Nam san xuat:" << g->data.namSX<<endl;
		cout << "Xep hang:" << g->data.XepHang<<endl;
		cout << endl;
	}
	cout << endl;
}

int main() {
	List l;
	int choose=0;
	while (true) {
		system("cls");
		cout << "\n\n\t\t======MENU======";
		cout << "\n\t1. Nhap danh sach";
		cout << "\n\t2.Xuat danh sach";
		cout << "\n\t3.Sap xep theo nam san xuat(tang dan)";
		cout << "\n\t4.Xoa phim co nha san xuat la 'HBO'";
		cout << "\n\t0.Thoat";
		cout << "\n\n\t\t======END======" << endl;

		cout << "Nhap lua chon:"; cin >> choose;

		if (choose < 0 || choose>4) {
			cout << "Lua chon khong hop le" << endl;

		}
		if (choose == 1) {
			dsNhap(l);
		}
		else if (choose == 2) {
			dsXuat(l);
			system("pause");
		}
		else if (choose == 3) {
			
			sapxep_Namsanxuat(l);
			cout << "Sau khi sap xep" << endl;
			dsXuat(l);
			system("pause");
		}
		else if (choose == 4) {
			xoa_nsxHBO(l);
			cout << "Sau khi xoa" << endl;
			dsXuat(l);
			system("pause");
		}
		else {
			break;
		}
	}
	
}