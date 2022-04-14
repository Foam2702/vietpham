#include<iostream>
using namespace std;

/*Cau truc node of LList*/
struct Node {
	int data;
	Node* Next;
};
/*Cau truc LList*/
struct List {
	Node* Head;
	Node* Tail;
};

/*Khoi tao LList*/
void init(List& l) {
	l.Head = l.Tail = NULL;
}
/*Khoi tao node*/
Node* createNode(int value) {
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
void addFirst(List& l, Node*p) {
	
	if (l.Head == NULL) {
		l.Head = p;
	}
	else {
		p->Next = l.Head;
		l.Head = p;
	}
}
/*Them 1 node vao cuoi LList*/
void addLast(List& l,Node*p) {
	
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
/*Them 1 node vao truoc node p*/
void insertMidList(List& l, Node* p,Node* q) {
	if (p->data == l.Head->data && l.Head->Next == NULL) {
		addFirst(l, q);
	}
	else {
		Node* k = new Node;
		for (Node* g = l.Head; g; g = g->Next) {
			if (p->data == g->data) {
				q->Next = g;
				k->Next = q;
			}
			k = g;
		}
	}
}
/*Nhap danh sach*/
void dsNhap(List& l) {
	int n,value;
	cout << "Nhap so luong phan tu can nhap:"; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Gia tri:"; cin >> value;
		Node* p = createNode(value);
		addLast(l, p);
	}
}
/*Xuat danh sach*/
void dsXuat(List l) {
	for (Node* g = l.Head; g; g = g->Next) {
		cout << g->data << " ";
	}
	cout << endl;
}
/*Tim node co khoa cho truoc*/
Node* SearchNode(List l, int key) {
	Node* node = l.Head;
	
	while (node != NULL)
	{
		
		if (node->data == key) {
			return node;
			break;
		}
		else {
			node = node->Next;
		}
		
	}
	return NULL;
	
}
/*Xoa 1 node(key)*/
void removeEntry(List& l, int key) {
	Node* temp = l.Head;
	Node* prev = NULL;

	if (temp != NULL && temp->data == key) {
		l.Head = temp->Next;
		delete temp;
		return;
	}
	
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->Next;
	}

	
	if (temp == NULL) return;

	
	prev->Next = temp->Next;

	delete temp;
}

int main() {
	List l; 
	Node* p;
	Node* q;
	init(l);
	int  value,ins,luachon;
	while (true) {
		system("cls");
		cout << "\n\n\t\t======MENU======";
		cout << "\n\t1. Them node vao truoc danh sach";
		cout << "\n\t2.Them node vao sau danh sach";
		cout << "\n\t3.Xuat danh sach";
		cout << "\n\t4.Them node q vao truoc node q";
		cout << "\n\t5.Tim node";
		cout << "\n\t6.Xoa node";
		cout << "\n\t7.Nhap danh sach";
		cout << "\n\t0.Thoat";
		cout << "\n\n\t\t======END======" << endl;
		cout << "Nhap lua chon:"; cin >> luachon;
		if (luachon < 0 || luachon>7) {
			cout << "Lua chon khong hop le" << endl;
		}
		if (luachon == 1) {

			cout << "Nhap gia tri:";
			cin >> value;
			p = createNode(value);
			addFirst(l, p);


		}
		else if (luachon == 2) {
			cout << "Nhap gia tri:";
			cin >> value;
			p = createNode(value);
			addLast(l, p);
		}
		else if (luachon == 3) {
			dsXuat(l);
			system("pause");
		}
		else if (luachon == 4) {
			cout << "Nhap vi tri node chen:"; cin >> ins;
			p = createNode(ins);
			cout << "Nhap gia tri node can chen:"; cin >> value;
			q = createNode(value);
			insertMidList(l, p, q);
			dsXuat(l);
			system("pause");
		}
		else if (luachon == 5) {
			cout << "Nhap gia tri can tim:"; cin >> value;
			p = SearchNode(l, value);
			cout << p->data << endl;
			system("pause");
		}
		else if (luachon == 6) {
			cout << "Nhap gia tri node can xoa:"; cin >> value;
			removeEntry(l, value);
			dsXuat(l);
			system("pause");
		}
		else if (luachon == 7) {
			dsNhap(l);
		}
		else if (luachon == 0) {
			break;
		}
	}
	

}