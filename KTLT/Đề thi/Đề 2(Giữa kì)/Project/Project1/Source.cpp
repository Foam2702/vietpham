#include<iostream>
#include<string>
using namespace std;

struct phuongtien
{
	string maso;
	string loai;
	int trongtai=0;
	bool trangthai=true;
};

struct Node
{
	phuongtien data;
	Node* pNext = NULL;
};
struct List
{
	Node* pHead = NULL;
};
Node* InitNode(phuongtien value)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "ERROR";
	}
	else
	{
		p->data = value;
		p->pNext = NULL;
	}
	return p;
}

void Add(List& l, phuongtien value)
{
	if (l.pHead == NULL)
	{
		Node* p = InitNode(value);
		l.pHead = p;
	}
	else
	{
		Node* g = l.pHead;
		while (g->pNext)
		{
			g = g->pNext;
		}
		g->pNext = InitNode(value);
	}
}

void Input(List &l)
{	
	
	int n;
	phuongtien data;
	cout << "Nhap so luong muon them:"; cin >> n;
	for (int i = 0; i < n; i++)
	{	
		cin.ignore();
		cout << "--Xe " << i+1 <<"--"<< endl;
		cout << "Ma so:";    
		getline(cin, data.maso);
		cout << "Loai xe:";   
		getline(cin, data.loai);
		cout << "Trong tai:"; 
		cin >> data.trongtai;
		cout << "1:Trong , 0:Ban :"; 
		cin >> data.trangthai;
		if (data.trangthai == 1)
		{
			data.trangthai = true;
		}
		else 
		{
			data.trangthai = false;
		}
		Add(l, data);
	}
}
void ExportList(List l)
{
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		cout << "Ma so:" << g->data.maso << endl;
		cout << "Loai xe:" << g->data.loai << endl;
		cout << "Trong tai:" << g->data.trongtai << endl;
		if (g->data.trangthai == true)
		{
			cout << "Trang thai:" << "Trong"<<endl;
		}
		else
		{
			cout << "Trang thai:" << "Ban"<<endl;
		}
	}
}
void Find_ByCode(List l)
{	
	string maso;
	cout << "Nhap ma so can tim:";
	getline(cin, maso);
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		if (g->data.maso == maso)
		{
			cout << "Ma so:" << g->data.maso << endl;
			cout << "Loai xe:" << g->data.loai << endl;
			cout << "Trong tai:" << g->data.trongtai << endl;
			if (g->data.trangthai == true)
			{
				cout << "Trang thai:" << "Trong" << endl;
			}
			else
			{
				cout << "Trang thai:" << "Ban" << endl;
			}
			break;
			
		}
	}
}

void Find_Empty(List l)
{
	for (Node* g = l.pHead; g; g = g->pNext)
	{
		if (g->data.trangthai == true)
		{
			cout << "Ma so:" << g->data.maso << endl;
			cout << "Loai xe:" << g->data.loai << endl;
			cout << "Trong tai:" << g->data.trongtai << endl;
			if (g->data.trangthai == true)
			{
				cout << "Trang thai:" << "Trong" << endl;
			}
			else
			{
				cout << "Trang thai:" << "Ban" << endl;
			}
		}
	}
}
void Update_Code(List& l)
{
	string maso;
	cout << "Nhap ma so can cap nhat:";
	getline(cin, maso);
	for (Node* g = l.pHead; g ; g = g->pNext)
	{
		if (g->data.maso == maso)
		{
			cout << "Cap nhat lai ma so:";
			getline(cin, g->data.maso);
			cout << "Sau khi cap nhat" << endl;
			cout << "Ma so:" << g->data.maso << endl;
			cout << "Loai xe:" << g->data.loai << endl;
			cout << "Trong tai:" << g->data.trongtai << endl;
			if (g->data.trangthai == true)
			{
				cout << "Trang thai:" << "Trong" << endl;
			}
			else
			{
				cout << "Trang thai:" << "Ban" << endl;
			}
		}
	}
}
void Menu()
{
	int luachon;
	List l;
	while (true)
	{
		system("cls");
		cout << "1:Nhap thong tin phuong tien"<<endl;
		cout << "2:In danh sach phuong tien trong"<<endl;
		cout << "3:Tim phuong tien"<<endl;
		cout << "4:Cap nhat lai phuong tien (ma so):" << endl;
		cout << "0:Thoat"<<endl;
		cout << "Nhap lua chon:";
		cin >> luachon;
		cin.ignore();

		switch (luachon)
		{
			case 1: 
				Input(l);
				break;
			case 2: 
				Find_Empty(l);
				system("pause");
				break;
			case 3:
				Find_ByCode(l);
				system("pause");
				break;
			case 4:
				Update_Code(l);
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