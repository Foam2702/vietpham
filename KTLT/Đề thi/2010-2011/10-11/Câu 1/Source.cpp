#include<iostream>
#include<string>
using namespace std;

struct SinhVien
{
	int maso;
	string hoten;
	int namsinh;
	string lophoc;
	float dtb;

};
struct Node
{
	SinhVien data;
	Node* pNext = NULL;
};

struct List
{
	Node* pHead = NULL;
};

Node* InitNode(SinhVien sv)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "ERRPR";

	}
	else
	{
		p->data = sv;
		p->pNext = NULL;
	}
	return p;
}
void AddTailtoList(List& l, SinhVien sv)
{


	if (l.pHead == NULL)
	{
		Node* p = InitNode(sv);
		l.pHead = p;
	}
	else
	{
		Node* g = l.pHead;
		while (g->pNext)
			g = g->pNext;
		g->pNext = InitNode(sv);
	}
}
void InputSV(List &l)
{
	
	int n;
	SinhVien sv;
	cout << "Nhap so luong sinh vien:"; cin >> n;
	for (int i = 0; i < n; i++)
	{	
		cin.ignore();
		cin >> sv.maso; cin.ignore();
		getline(cin, sv.hoten);
		cin >> sv.namsinh; cin.ignore();
		getline(cin, sv.lophoc);
		cin >> sv.dtb; 
		AddTailtoList(l, sv);
	}
}
void ExportList(List l)
{
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		cout << g->data.maso << endl;
		cout << g->data.hoten << endl;
		cout << g->data.namsinh << endl;
		cout << g->data.lophoc << endl;
		cout << g->data.dtb << endl;
	}
}
void ExportStu_HighGrades(List l)
{	
	Node* check = new Node;
	for (Node* g = l.pHead; g->pNext; g = g->pNext)
	{	
		if (g->data.dtb < g->pNext->data.dtb)
			check = g->pNext;

	}
	cout << check->data.maso << endl;
	cout << check->data.hoten << endl;
	cout << check->data.namsinh << endl;
	cout << check->data.lophoc << endl;
	cout << check->data.dtb << endl;
	
}
void ExportList_Increasing(List& l)
{
	for (Node* g = l.pHead; g->pNext; g = g->pNext)
	{
		for (Node* k = l.pHead->pNext; k; k = k->pNext)
		{
			if (g->data.dtb > k->data.dtb)
				swap(g->data, k->data);
		}
	}
	ExportList(l);
}
void DestroyList(List& l)
{
	Node* p = l.pHead;
	while (l.pHead)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

int main()
{	
	List l;
	InputSV(l);
	cout << endl;
	ExportList(l);
	cout << endl;
	ExportStu_HighGrades(l);
	cout << endl;
	ExportList_Increasing(l);
	DestroyList(l);

	return 0;
}

