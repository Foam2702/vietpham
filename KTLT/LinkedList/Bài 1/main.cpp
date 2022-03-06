#include<iostream>
#include<cmath>
using namespace std;

struct Node {
	int data=0;
	Node* pNext=NULL;
};
struct List {
	Node* pHead;
	Node* pTail;
};

Node* CreateNode(int x) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "NOT ENOUGH MEMORY";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void CreateList(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
void AddFirst(List& l, int x) {
	Node* p = CreateNode(x);
	if (l.pHead == NULL) {
		l.pHead = l.pTail =p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void DestroyList(List& l) {
	Node* p;
	while (l.pHead) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
void AddLast(List& l, int x) {
	Node* p = CreateNode(x);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	//cách 1
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
	//cách 2
	/*if (l.pHead == NULL) {
		l.pHead = CreateNode(x);
	}
	else {
		p = l.pHead;
		while (p->pNext) {
			p = p->pNext;
		}
		p = CreateNode(x);
	}*/
	
	
}
void SearchNode(List l) {
	int i = 1;
	int searchvalue = 0;
	cout << "Nhap node can tim:"; cin >> searchvalue;
	if (l.pHead == NULL) {
		cout << "Danh sach rong";
	}
	for (Node* g = l.pHead; g; g = g->pNext) {
		if (searchvalue == g->data) {
			cout << "Node thu "<< i<<":"<<g->data;
		}
		i++;
	}
}
void AddNodetoAnywhere(List& l, int x,int pos) {
	int n = 0;
	
	for (Node* g = l.pHead; g; g = g->pNext) {
		n++;
	}
	if (pos == 1||l.pHead==NULL) {
		AddFirst(l, x);
	}
	else if (pos == n+1) {
		AddLast(l, x);
	}
	else {
		Node* q = new Node;
		int count = 0;
		for (Node* k = l.pHead;k; k = k->pNext) {
			count++;
			if (pos==count) {
				Node* p = CreateNode(x);
				p->pNext = k;
				q->pNext = p;
				break;
			}
			q = k;
			
		}
	}
}
void DeleteHead(List& l) {
	if (l.pHead == NULL) {
		return;
	}
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void DeleteTail(List& l) {
	if (l.pHead == NULL) {
		return;
	}
	Node* g = new Node;
	for (Node* p = l.pHead; p; p = p->pNext) {
		if (p->pNext == NULL) {
			delete p;
			g->pNext = NULL;
			return;
		}
		g = p;
	}
}
void DeleteNodeatAnywhere(List& l, int pos) {
	
	int n = 0;
	for (Node* g = l.pHead; g; g = g->pNext) {
		n++;
	}
	if (pos == 1 || l.pHead == NULL) {
		DeleteHead(l);
		return;
	}
	else if (pos == n) {
		DeleteTail(l);
		return;
	}
	int count = 0;
	Node* k = new Node;
	for (Node* g = l.pHead; g; g = g->pNext) {
		count++;
		if (pos == count) {
			k->pNext = g->pNext;
			delete g;
			break;
		}
		k = g;
	}
	
}
void ExportList(List &l) {
	for (Node* g = l.pHead;g; g = g->pNext) {
		cout << g->data << " ";
	}
}
bool Increasing(int x, int y) {
	return x < y;
}
bool Decreasing(int x, int y) {
	return x > y;
}
void QuickSortIncreasingList(List& l) {
	List l1, l2;
	Node* tag, * p;
	if (l.pHead == l.pTail)return;
	CreateList(l1); CreateList(l2);
	tag = l.pHead;
	l.pHead = l.pHead->pNext;
	tag->pNext = NULL;//cô lập tag
	
	while (l.pHead) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;//cập nhật pHead
		p->pNext = NULL;//cô lập p
		if (p->data<=tag->data) {
			AddLast(l1, p->data);
		}
		else {
			AddLast(l2, p->data);
		}
	}
	QuickSortIncreasingList(l1);
	QuickSortIncreasingList(l2);
	
	if (l1.pHead != NULL) {
		l.pHead = l1.pHead;
		l1.pTail->pNext = tag;
	}
	else l.pHead = tag;

	tag->pNext = l2.pHead;

	if (l2.pHead != NULL) l.pTail = l2.pTail;
	else l.pTail = tag;
	
}
void QuickSortDecreasingList(List& l) {
	List l1, l2;
	Node* tag, * p;
	if (l.pHead == l.pTail)return;
	CreateList(l1); CreateList(l2);
	tag = l.pHead;
	l.pHead = l.pHead->pNext;
	tag->pNext = NULL;//cô lập tag

	while (l.pHead) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;//cập nhật pHead
		p->pNext = NULL;//cô lập p
		if (p->data >= tag->data) {
			AddLast(l1, p->data);
		}
		else {
			AddLast(l2, p->data);
		}
	}
	QuickSortDecreasingList(l1);
	QuickSortDecreasingList(l2);

	if (l1.pHead != NULL) {
		l.pHead = l1.pHead;
		l1.pTail->pNext = tag;
	}
	else l.pHead = tag;

	tag->pNext = l2.pHead;

	if (l2.pHead != NULL) l.pTail = l2.pTail;
	else l.pTail = tag;

}
void Menu() {
	List l;
	CreateList(l);
	int choose = 0;
	do{
		system("cls");
		cout << "1:Them node vao dau danh sach(Nhap 0 de dung qua trinh nhap)" << endl;
		cout << "2:Them node vao cuoi danh sach(Nhap 0 de dung qua trinh nhap)" << endl;
		cout << "3:Xuat danh sach" << endl;
		cout << "4:Tim Node" << endl;
		cout << "5:Them Node vao vi tri bat ky" << endl;
		cout << "6:Xoa Node tai vi tri bat ky" << endl;
		cout << "7:Sap xep danh sach lien ket tang dan(QuickSort)" << endl;
		cout <<	"8:Sap xep danh sach lien ket giam dan(QuickSort)" << endl;
		cout << "9:Xoa tat ca node trong danh sach" << endl;
		cout << "0:Thoat" << endl;
		cout << "Nhap lua chon:"; cin >> choose;
		switch (choose) {
			case 1: {
				int x = NULL;
				do {

					cout << "Nhap gia tri cua node:"; cin >> x;
					if (x != 0) {
						AddFirst(l, x);
					}

				} while (x != 0);
				break;
			}
			case 2: {
				int x = NULL;
				do {
					cout << "Nhap gia tri cua node:"; cin >> x;
					if (x != 0) {
						AddLast(l, x);
					}

				} while (x != 0);
				break;
			}
			case 3: {
				ExportList(l);
				system("pause");
				break;
			}
			case 4: {
				SearchNode(l);
				break;
			}
			case 5: {
				int value, pos;
				cout << "Nhap gia tri Node muont them:"; cin >> value;
				cout << "Vi tri muon them:"; cin >> pos;
				AddNodetoAnywhere(l, value, pos);
				break;
			}
			case 6: {
				int pos = 0;
				cout << "Vi tri muon xoa:"; cin >> pos;
				DeleteNodeatAnywhere(l, pos);
				break;
			}
			case 7: {
				QuickSortIncreasingList(l);
				ExportList(l);
				system("pause");
				break;
			}
			case 8: {
				QuickSortDecreasingList(l);
				ExportList(l);
				system("pause");
				break;
			}
			case 9: {
				DestroyList(l);
				break;
			}
		}
	} while (choose != 0);
}
int main(){

	Menu();
	return 0;

}