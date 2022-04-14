#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;
	Node* pPrev;
};
struct List
{
	Node* pHead=NULL;
	Node* pTail=NULL;
};

Node* InitNode(int value)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
		
	}
	else
	{
		p->data = value;
		p->pNext = p->pPrev = NULL;
	}
	return p;
}

void InitList(List& l, Node*& head)
{
	if (l.pHead == NULL)
	{
		l.pHead = head;
	}
}
int countNode(List l)
{
	int count = -1;
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		count++;
	}
	return count;
}

void removefirstElement(List& l)
{	
	if (l.pHead == NULL)
		return;
	Node* g = l.pHead;
	l.pHead = l.pHead->pNext;
	delete g;
	if(l.pHead!=NULL)
		l.pHead->pPrev = NULL;
}
void removelastElement(List& l)
{	
	if (l.pHead == NULL)
		return;
	else {
		for (Node* g = l.pHead; g; g = g->pNext)
		{
			if (g->pNext == NULL)
			{	
				Node* del = g;
				g = g->pPrev;
				g->pNext = NULL;

			}
		}
	}
}
void removeAllElement(List& l)
{
	while (l.pHead)
	{
		removefirstElement(l);
	}
}
void removeindexElement(List& l, int index)
{	

	int count = 0;
	int maxindex = countNode(l);
	
	if (index == 0)
	{
		removefirstElement(l);
	
	}
	else if (index == maxindex + 1 )
	{
		removelastElement(l);
	}
	else {
		for (Node* g = l.pHead; g; g = g->pNext)
		{
			if (count == index)
			{
				Node* del = g;
				g->pPrev->pNext = g->pNext;
				g->pNext->pPrev = g->pPrev;
				delete del;
				break;
			}

			count++;
		}
	}
}
void AddFirstElement(List& l, int value)
{
	Node* p = InitNode(value);
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		l.pHead->pPrev = p;
		p->pNext = l.pHead;
		l.pHead = p;

	}
}
void AddLastElement(List& l, int value)
{
	Node* p = InitNode(value);
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		Node* g = l.pHead;
		while (g->pNext)
			g = g->pNext;
		p->pPrev = g;
		g->pNext = p;
		
	}
}
void AddIndexElement(List&l, int index, int value)
{	
	int count = 0;
	int maxindex = countNode(l);
	Node* p = InitNode(value);
	

	if (index == 0)
	{
		AddFirstElement(l,value);
	}
	else if (index == maxindex+1) {
		AddLastElement(l, value);
	}
	else
	{
		for (Node* g = l.pHead; g; g = g->pNext)
		{
			if (count == index)
			{	

				p->pNext = g;
				g->pPrev->pNext = p;
				break;

			}
			count++;
		}
	}
}
void removeDuplicate(List& l)
{
	Node* g = l.pHead;
	Node* h = new Node;
	Node* dup = new Node;
	while (g && g->pNext)
	{
		h = g;
		while (h->pNext)
		{
			if (g->data == h->pNext->data)
			{
				dup = h->pNext;
				h->pNext = h->pNext->pNext;
				delete dup;
			}
			else
				h = h->pNext;
		}
		g = g->pNext;
	}
}

void ExportList(List l)
{
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		cout << g->data << " ";
	}
}

void Menu() {
	List l;
	int choose = 0;
	do {
		system("cls");
		cout << "1:Khoi tao danh sach lien ket voi gia tri head" << endl;
		cout << "2:Them node vao dau danh sach(Nhap Ctrl+W de dung)" << endl;
		cout << "3:Xuat danh sach" << endl;
		cout << "4:Xoa Node tai vi tri dau tien" << endl;
		cout << "5:Xoa Node tai vi tri bat ky" << endl;
		cout << "6:Xoa tat ca node trong danh sach" << endl;
		cout << "7:Them Node vao vi tri bat ky" << endl;
		cout << "8:Xoa Duplicate" << endl;
		cout << "0:Thoat" << endl;
		cout << "Nhap lua chon:"; cin >> choose;
		switch (choose) {
			case 1: {
				int head;
				cout << "Nhap head:"; cin >> head;
				Node* pHead = InitNode(head);
				InitList(l, pHead);
				break;
			}
			case 2: {
				int value;
				cout << "Nhap node:";
				while (cin >> value)
				{
					cout << "Nhap node:";
					AddFirstElement(l, value);
				}
				cin.clear();
				cin.ignore();
				break;
			}
			case 3: {
				ExportList(l);
				system("pause");
				break;
			}
			case 4: {
				removefirstElement(l);
				cout << "Danh sach sau khi xoa:";
				ExportList(l);
				system("pause");
				break;
			}
			case 5: {
				int count = countNode(l);
				int index = 0;
				cout << "Nhap vi tri can xoa (0->" << count << "):"; cin >> index;
				removeindexElement(l, index);
				cout << "Danh sach sau khi xoa:";
				ExportList(l);
				system("pause");
				break;
			}
			case 6: {
				removeAllElement(l);
				cout << "Danh sach sau khi xoa:";
				ExportList(l);
				system("pause");
				break;

			}
			case 7: {
				int count = countNode(l);
				int index = 0;
				int value = 0;
				cout << "Nhap gia tri can them:"; cin >> value;
				cout << "Nhap vi tri can them (0->" << count + 1 << "):"; cin >> index;
				AddIndexElement(l, index, value);
				cout << "Danh sach sau khi them:";
				ExportList(l);
				system("pause");
				break;
			}
			case 8: {
				removeDuplicate(l);
				cout << "Danh sach sau khi xoa:";
				ExportList(l);
				system("pause");
				break;

			}
		}
	} while (choose != 0);
}

int main()
{
	Menu();
}